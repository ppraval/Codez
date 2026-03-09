"""
redact_pdf.py
-------------
Redacts patient-sensitive fields from endoscopy report PDFs.

Fields redacted:
  Header  — Patient ID value, Patient Name value, Age/Gender value,
             Visit Date value, Referred by value, Performed by value
  Footer  — Doctor name line

Usage:
    python redact_pdf.py <input.pdf> [output.pdf]

If output path is omitted, saves as <input>_redacted.pdf in the same folder.

Dependencies:
    pip install pymupdf
"""

import re
import sys
import os
import fitz  # PyMuPDF


# ── Header label detection ──────────────────────────────────────────────────
# We do NOT use page.search_for() for labels — it silently fails when the PDF
# stores label text across split/encoded font spans.
# Instead we cluster all words into visual lines and substring-match the
# joined line text, which is always reliable.

# Standalone patterns (redact the whole match, not just a value after a label)
STANDALONE_PATTERNS = [
    # Doctor signature line at the bottom, e.g. "Dr Sunil Kumar K, MD, DM"
    r'Dr\s+[A-Z][a-zA-Z\s]+,\s*(?:MD|MBBS|MS|DM)[,\s\w]*',
    # Software branding footer right side, e.g. "CaptureITPro - www.ambalsoft.com"
    r'CaptureITPro\s*[-–]\s*[\w\.]+',
    # Any URL in the footer
    r'www\.[a-zA-Z0-9\-]+\.[a-zA-Z]{2,}(?:/[\w\-\.]*)*',
]

# How many points from the bottom of the page to treat as the footer zone.
# Standard A4/Letter page is ~842pt tall; 70pt covers ~2.5 cm.
FOOTER_HEIGHT_PT = 70


def redact_header_values(page: fitz.Page) -> int:
    """
    Fully word-based header redaction.
    1. Cluster all words into visual lines (±5 pt vertically).
    2. For each header line, split it into left/right column segments at the
       largest horizontal gap (the inter-column whitespace) so both columns
       are processed independently.
    3. For each segment, find ':' and redact every word after it.
    """
    words = page.get_text("words")  # (x0,y0,x1,y1, text, block, line, word_no)
    if not words:
        return 0

    page_width = page.rect.width
    LINE_TOL = 5  # pt — vertical tolerance for grouping words into one line
    # Minimum gap to treat as an inter-column separator (~4% of page width ≈ 24pt on A4)
    MIN_COLUMN_GAP = page_width * 0.04

    # --- Cluster words into visual lines ---
    lines = []
    for w in words:
        cy = (w[1] + w[3]) / 2
        best, best_d = None, LINE_TOL + 1
        for i, line in enumerate(lines):
            ref = (line[0][1] + line[0][3]) / 2
            d = abs(cy - ref)
            if d < best_d:
                best, best_d = i, d
        if best is not None:
            lines[best].append(w)
        else:
            lines.append([w])
    for line in lines:
        line.sort(key=lambda w: w[0])

    def is_header_segment(t: str) -> bool:
        return any([
            'patient id'   in t,
            'patient name' in t,
            ('age' in t and 'gender' in t),
            'visit date'   in t,
            'referred by'  in t,
            'performed by' in t,
        ])

    count = 0

    def process_segment(seg: list) -> None:
        nonlocal count
        seg_text = ' '.join(w[4] for w in seg).lower()
        if not is_header_segment(seg_text):
            return
        # Find colon; everything to its right is a value word
        colon_x = seg[0][2]
        for w in seg:
            if ':' in w[4]:
                colon_x = w[2]
                break
        for w in seg:
            if w[0] > colon_x:
                r = fitz.Rect(w[0] - 1, w[1] - 1, w[2] + 1, w[3] + 1)
                page.add_redact_annot(r, fill=(0, 0, 0))
                count += 1

    for line in lines:
        line_text = ' '.join(w[4] for w in line).lower()
        if not is_header_segment(line_text):
            continue

        # Split at the largest inter-word gap to separate the two table columns
        max_gap, split_after = 0, -1
        for i in range(len(line) - 1):
            gap = line[i + 1][0] - line[i][2]
            if gap > max_gap:
                max_gap, split_after = gap, i

        if max_gap >= MIN_COLUMN_GAP and split_after >= 0:
            process_segment(line[:split_after + 1])   # left column
            process_segment(line[split_after + 1:])   # right column
        else:
            process_segment(line)

    if count:
        page.apply_redactions(images=fitz.PDF_REDACT_IMAGE_NONE)

    return count


def extract_standalone_strings(page_text: str) -> list[str]:
    """Return standalone sensitive substrings (doctor names, branding, URLs)."""
    targets = []
    for pat in STANDALONE_PATTERNS:
        for m in re.finditer(pat, page_text, re.IGNORECASE):
            targets.append(m.group(0).strip())

    seen = set()
    unique = []
    for t in targets:
        if t and t not in seen:
            seen.add(t)
            unique.append(t)
    return unique


def redact_footer_zone(page: fitz.Page) -> int:
    """
    Redact the entire horizontal strip at the bottom of the page
    (covers doctor signature + software branding line regardless of exact text).
    """
    pw, ph = page.rect.width, page.rect.height
    footer_rect = fitz.Rect(0, ph - FOOTER_HEIGHT_PT, pw, ph)
    page.add_redact_annot(footer_rect, fill=(1, 1, 1))  # white fill keeps layout clean
    page.apply_redactions(images=fitz.PDF_REDACT_IMAGE_NONE)
    return 1


def redact_page(page: fitz.Page) -> int:
    """
    Redact all sensitive content on a single page.
    1. Word-level header value redaction (robust against split text spans).
    2. Standalone pattern redaction (doctor names, branding, URLs elsewhere).
    3. Full footer zone wipe.
    Returns total number of redactions applied.
    """
    # 1. Header fields — word-level, handles two-column layout
    count = redact_header_values(page)

    # 2. Standalone patterns for anything outside the header
    page_text = page.get_text("text")
    targets = extract_standalone_strings(page_text)
    standalone_count = 0
    for target in targets:
        rects = page.search_for(target, quads=False)
        for rect in rects:
            padded = fitz.Rect(rect.x0 - 2, rect.y0 - 1, rect.x1 + 2, rect.y1 + 1)
            page.add_redact_annot(padded, fill=(0, 0, 0))
            standalone_count += 1
    if standalone_count:
        page.apply_redactions(images=fitz.PDF_REDACT_IMAGE_NONE)
    count += standalone_count

    # 3. Always wipe the full footer strip
    count += redact_footer_zone(page)

    return count


OUTPUT_DIR = r'E:/gmc_data/redacted'


def redact_pdf(input_path: str, output_path: str | None = None) -> str:
    """
    Open input_path, redact all sensitive fields on every page,
    and save to output_path.
    Defaults to OUTPUT_DIR/<original_filename>.
    Returns the output path.
    """
    if output_path is None:
        os.makedirs(OUTPUT_DIR, exist_ok=True)
        fname = os.path.basename(input_path)
        output_path = os.path.join(OUTPUT_DIR, fname)

    doc = fitz.open(input_path)
    total_redactions = 0

    for page_num, page in enumerate(doc, start=1):
        n = redact_page(page)
        if n:
            print(f"  Page {page_num}: {n} redaction(s) applied")
        total_redactions += n

    doc.save(output_path, garbage=4, deflate=True)
    doc.close()

    print(f"\nTotal redactions: {total_redactions}")
    print(f"Saved redacted PDF to: {output_path}")
    return output_path


# ── Entry point ──────────────────────────────────────────────────────────────
TEST_FILES = [
    r"D:\gmc_data\varices\BAIJU_1486\12Nov2024_134525\BAIJU_183305_RP241112_015802.pdf",
    r"D:\gmc_data\varices\BABEESH_1253\30Oct2024_094923\BABEESH_79449_RP241030_101003.pdf",
    r"D:\gmc_data\varices\BALAKRISHNAN_938\11Oct2024_115408\BALAKRISHNAN_0017644_RP241011_011341.pdf",
    r"D:\gmc_data\varices\BALAKRISHNAN_938\11Oct2024_115408\BALAKRISHNAN_0017644_RP241011_011410.pdf",
]

if __name__ == "__main__":
    files = sys.argv[1:] if len(sys.argv) > 1 else TEST_FILES

    for input_file in files:
        if not os.path.isfile(input_file):
            print(f"[ERROR] File not found: {input_file}\n")
            continue
        print(f"Redacting: {input_file}")
        redact_pdf(input_file)
        print()
