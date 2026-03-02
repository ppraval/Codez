import os
import re
import shutil
import PyPDF2


def extract_highest_grade(pdf_path):
    """
    Read a PDF and return the highest esophageal varices grade found (1, 2, or 3).
    Handles roman numerals (I/II/III) and arabic numerals (1/2/3).
    Example match: 'Esophagus : grade IIIx2 ,IIx1 ...'
    """
    try:
        with open(pdf_path, 'rb') as file:
            reader = PyPDF2.PdfReader(file)
            text = ""
            for page in reader.pages:
                extracted = page.extract_text()
                if extracted:
                    text += extracted
    except Exception as e:
        print(f"  [ERROR] Could not read {pdf_path}: {e}")
        return None

    # Match 'grade' followed by:
    #   - roman numerals : III / II / I  (longest first to avoid partial matches)
    #   - arabic numerals: 3 / 2 / 1
    #   - written words  : three / two / one
    # Handles suffixes like 'x2' in 'grade IIIx2'.
    pattern = re.compile(
        r'\bgrade[\s\-]*(III|II|I|[1-3]|three|two|one)(?:x\d+)?',
        re.IGNORECASE
    )

    roman_to_int = {
        'III': 3, 'II': 2, 'I': 1,
        '3': 3, '2': 2, '1': 1,
        'THREE': 3, 'TWO': 2, 'ONE': 1,
    }

    highest = 0
    for match in pattern.finditer(text):
        grade_str = match.group(1).upper()
        grade_val = roman_to_int.get(grade_str, 0)
        if grade_val > highest:
            highest = grade_val

    return highest if highest > 0 else None


def get_highest_grade_in_folder(folder_path):
    """
    Walk a patient folder recursively, read every PDF,
    and return the single highest grade found across all PDFs.
    """
    highest = 0
    for root, dirs, files in os.walk(folder_path):
        for fname in files:
            if fname.lower().endswith('.pdf'):
                pdf_path = os.path.join(root, fname)
                grade = extract_highest_grade(pdf_path)
                if grade and grade > highest:
                    highest = grade
    return highest if highest > 0 else None


def grade_varices_folders(source_dir, dest_root):
    """
    For every top-level patient folder in source_dir:
      - Parse all PDFs recursively to find the highest varices grade.
      - Copy the patient folder into dest_root/Grade_I, /Grade_II, or /Grade_III.
    """
    grade_label = {1: 'Grade_I', 2: 'Grade_II', 3: 'Grade_III'}
    grade_dirs = {g: os.path.join(dest_root, label) for g, label in grade_label.items()}

    for gdir in grade_dirs.values():
        os.makedirs(gdir, exist_ok=True)

    entries = [e for e in os.listdir(source_dir)
               if os.path.isdir(os.path.join(source_dir, e))]

    print(f"Found {len(entries)} folders in source: {source_dir}\n")

    for folder_name in entries:
        folder_path = os.path.join(source_dir, folder_name)
        print(f"Processing: {folder_name}")

        highest_grade = get_highest_grade_in_folder(folder_path)

        if highest_grade is None:
            print(f"  -> No grade found — skipping\n")
            continue

        dest_folder = os.path.join(grade_dirs[highest_grade], folder_name)
        label = grade_label[highest_grade]

        if os.path.exists(dest_folder):
            print(f"  -> Already exists in {label} — skipping\n")
        else:
            shutil.copytree(folder_path, dest_folder)
            print(f"  -> Copied to {label}\n")

    print("Done.")


# ── Configuration ────────────────────────────────────────────────────────────
source_directory = 'D:/gmc_data/varices'
dest_directory   = 'E:/gmc_data/varices_graded'

grade_varices_folders(source_directory, dest_directory)
