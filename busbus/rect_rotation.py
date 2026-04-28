"""
Rectangle Rotation Analysis
============================

Rect A (fixed, landscape, BLUE) : 4800 × 3300  at (0,0)→(4800,3300)
Rect B (moving, portrait, ORANGE): starts fully overlapping Rect A,
  rotates 90°CW to final position:
    - Right edge 600 INSIDE Rect A's right  → x_right = 4800 − 600 = 4200
    - Top  edge  600 BELOW  Rect A's top    → y_top   =   0 + 600 =  600
    - Width = 3300, Height = 4800
    - Left = 4200 − 3300 = 900, Bottom = 600 + 4800 = 5400

PIVOT solved analytically:
  90°CW formula about (px,py): (x,y) → (px+(y−py),  py−(x−px))
  Using TR_start(4800,0) → TL_final(900,600):
    px − py = 900   ...(i)
    px + py = 5400  ...(ii)
    → px = 3150,  py = 2250
"""

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.patches import Polygon as MplPoly
from matplotlib.lines import Line2D
import os, warnings
warnings.filterwarnings("ignore")

OUT_DIR = os.path.dirname(os.path.abspath(__file__))

# ─── GEOMETRY ─────────────────────────────────────────────────────────────────
A_x0, A_y0, A_x1, A_y1 = 0, 0, 4800, 3300          # Rect A (landscape)

# Rect B final position (portrait 3300×4800)
B_fx0, B_fy0 = 900,  600      # left, top
B_fx1, B_fy1 = 4200, 5400     # right, bottom

B_start = np.array([[A_x0,A_y0],[A_x1,A_y0],[A_x1,A_y1],[A_x0,A_y1]], dtype=float)
B_final = np.array([[B_fx0,B_fy0],[B_fx1,B_fy0],[B_fx1,B_fy1],[B_fx0,B_fy1]], dtype=float)

PIVOT = np.array([3150.0, 2250.0])

print("=" * 60)
print("GEOMETRY")
print("=" * 60)
print(f"Rect A         : ({A_x0},{A_y0}) → ({A_x1},{A_y1})  [4800×3300]")
print(f"Rect B (final) : ({B_fx0},{B_fy0}) → ({B_fx1},{B_fy1})  [3300×4800]")
print(f"  Right = {B_fx1} = 4800 − 600  ✓  (600 inside A right)")
print(f"  Top   = {B_fy0} = 0   + 600  ✓  (600 below A top)")
print(f"\nPIVOT (analytical) : {PIVOT}")

# ─── VERIFY ───────────────────────────────────────────────────────────────────
def rot90cw(pts, piv):
    """90°CW rotation (screen-coords: y down) about piv."""
    px, py = piv
    dx, dy = pts[:, 0] - px, pts[:, 1] - py
    return np.column_stack([px + dy, py - dx])

def rot_angle(pts, piv, deg):
    """Arbitrary CW rotation in screen-coords."""
    px, py = piv
    a = np.deg2rad(deg)
    dx, dy = pts[:, 0] - px, pts[:, 1] - py
    rx = px + dx * np.cos(a) + dy * np.sin(a)
    ry = py - dx * np.sin(a) + dy * np.cos(a)
    return np.column_stack([rx, ry])

computed = rot90cw(B_start, PIVOT)
# TL_start→BL_final, TR_start→TL_final, BR_start→TR_final, BL_start→BR_final
expected = [B_final[3], B_final[0], B_final[1], B_final[2]]
labels   = ["TL→BL_final", "TR→TL_final", "BR→TR_final", "BL→BR_final"]

print("\nCorner verification:")
all_ok = True
for lbl, got, exp in zip(labels, computed, expected):
    ok = np.allclose(got, exp)
    all_ok = all_ok and ok
    print(f"  {lbl:25s}: got {got.round(1)}  exp {exp}  {'✓' if ok else '✗'}")
print(f"  All correct: {all_ok}\n")

radii = [np.linalg.norm(c - PIVOT) for c in B_start]
cnames = ["TL (0,0)", "TR (4800,0)", "BR (4800,3300)", "BL (0,3300)"]
print("Arc radii (corner → pivot distance):")
for cn, r in zip(cnames, radii):
    print(f"  {cn:22s} → r = {r:8.2f}")

# ─── ARC HELPER ───────────────────────────────────────────────────────────────
def corner_arc(corner, piv, n=400):
    dx, dy = corner[0]-piv[0], corner[1]-piv[1]
    r = np.hypot(dx, dy)
    t0 = np.arctan2(dy, dx)
    # 90°CW in screen coords → angle decreases by π/2
    thetas = np.linspace(t0, t0 - np.pi/2, n)
    return piv[0] + r*np.cos(thetas), piv[1] + r*np.sin(thetas)

arcs = [corner_arc(c, PIVOT) for c in B_start]
arc_cols = ["#ff9ff3", "#ffeaa7", "#74b9ff", "#a29bfe"]

# ─── DRAWING HELPERS ──────────────────────────────────────────────────────────
DARK_BG  = "#0d1117"
PANEL_BG = "#161b22"
COL_A    = "#1d6fa4"
COL_B    = "#e07b39"
COL_PIV  = "#ff4444"
COL_GOLD = "#ffd700"

def draw_rect(ax, corners, fc, ec, alpha=0.3, lw=2.5, ls="-", zorder=2, label=None):
    patch = MplPoly(corners, closed=True, fc=fc, ec=ec,
                    alpha=alpha, lw=lw, ls=ls, zorder=zorder, label=label)
    ax.add_patch(patch)

def style(ax, title):
    ax.set_facecolor(PANEL_BG)
    ax.set_title(title, color="#c9d1d9", fontsize=10, pad=8)
    for sp in ax.spines.values():
        sp.set_edgecolor("#30363d")
    ax.tick_params(colors="#8b949e", labelsize=7)
    ax.set_xlabel("X", color="#8b949e", fontsize=8)
    ax.set_ylabel("Y", color="#8b949e", fontsize=8)

XLIM = (-600, 5800)
YLIM = (-400, 5500)
A_corners = np.array([[A_x0,A_y0],[A_x1,A_y0],[A_x1,A_y1],[A_x0,A_y1]], dtype=float)

# ══════════════════════════════════════════════════════════════════════════════
# FIGURE 1 — Reference position (matches the provided image)
# ══════════════════════════════════════════════════════════════════════════════
fig1, ax1 = plt.subplots(figsize=(10, 9), facecolor="white")
ax1.set_facecolor("white")
ax1.set_title(
    "Final Position  —  Blue=Rect A (4800×3300)  |  Orange=Rect B (3300×4800)\n"
    "Right edge 600 inside  ·  Top edge 600 below  ·  Pivot (3150, 2250)",
    fontsize=11, color="#222", pad=10
)

draw_rect(ax1, A_corners, COL_A, "#0d5a8a", alpha=0.9, lw=3, zorder=2)
draw_rect(ax1, B_final,   COL_B, "#c06020", alpha=0.9, lw=3, zorder=3)

# Dimension annotations
ax1.annotate("", xy=(4200, -200), xytext=(4800, -200),
             arrowprops=dict(arrowstyle="<->", color="black", lw=2))
ax1.text(4500, -310, "600", ha="center", fontsize=12, fontweight="bold", color="black")
ax1.text(4500, -130, "(right offset)", ha="center", fontsize=8, color="#555")

ax1.annotate("", xy=(-300, 0), xytext=(-300, 600),
             arrowprops=dict(arrowstyle="<->", color="black", lw=2))
ax1.text(-420, 300, "600", ha="center", fontsize=12, fontweight="bold",
         color="black", rotation=90)
ax1.text(-200, 300, "(top offset)", ha="left", fontsize=8, color="#555", rotation=90)

# Labels on rectangles
ax1.text(2400, 1650, "A\n4800×3300", ha="center", va="center",
         color="white", fontsize=14, fontweight="bold", alpha=0.8)
ax1.text(2550, 2410, "B\n3300×4800", ha="center", va="center",
         color="white", fontsize=14, fontweight="bold", alpha=0.8)

ax1.plot(*PIVOT, "*", color="red", ms=18, zorder=20, mec="white", mew=1)
ax1.annotate(f"PIVOT (3150, 2250)", xy=PIVOT,
             xytext=(PIVOT[0]-1400, PIVOT[1]+700),
             color="red", fontsize=10, fontweight="bold",
             arrowprops=dict(arrowstyle="->", color="red", lw=2))

ax1.set_xlim(-700, 5600); ax1.set_ylim(-600, 5500)
ax1.set_aspect("equal"); ax1.invert_yaxis()
ax1.set_xlabel("X (units)", fontsize=10); ax1.set_ylabel("Y (units)", fontsize=10)
ax1.grid(True, color="#ddd", alpha=0.4)
ax1.tick_params(colors="#555", labelsize=9)

plt.tight_layout()
out1 = os.path.join(OUT_DIR, "final_position.png")
plt.savefig(out1, dpi=150, bbox_inches="tight", facecolor="white")
print(f"\nSaved → final_position.png")

# ══════════════════════════════════════════════════════════════════════════════
# FIGURE 2 — Three-panel analysis
# ══════════════════════════════════════════════════════════════════════════════
fig2, axes = plt.subplots(1, 3, figsize=(24, 10), facecolor=DARK_BG)
fig2.suptitle(
    "Rect B  90°CW Rotation  ·  Pivot (3150, 2250)  ·  "
    "Right offset 600  ·  Top offset 600",
    fontsize=14, color="#e6edf3", fontweight="bold", y=0.98
)

# ── Panel 1: Start + Final + Corner arcs ──────────────────────────────────────
ax = axes[0]
style(ax, "Start → Final  |  Pivot & Corner Arcs")

draw_rect(ax, A_corners, COL_A, COL_A, alpha=0.2, lw=3, label="Rect A (fixed)")
ax.text(2400, 1650, "A\n4800×3300", ha="center", va="center",
        color="white", fontsize=11, fontweight="bold", alpha=0.5)

draw_rect(ax, B_start, COL_B, COL_B, alpha=0.25, lw=2, ls="--", label="B start (0°)")
ax.text(2400, 900,  "B START", ha="center", va="center",
        color=COL_B, fontsize=9, fontweight="bold", alpha=0.7)

draw_rect(ax, B_final, COL_B, "#ff7700", alpha=0.55, lw=3, zorder=5, label="B final (90°CW)")
ax.text(2550, 2410, "B FINAL", ha="center", va="center",
        color="#ff8844", fontsize=9, fontweight="bold")

for (ax_, ay_), lbl, col in zip(arcs, ["TL","TR","BR","BL"], arc_cols):
    ax.plot(ax_, ay_, color=col, lw=2, ls=":", alpha=0.9, label=f"{lbl} arc")
    mid = len(ax_)//2
    ax.annotate("", xy=(ax_[mid+5], ay_[mid+5]), xytext=(ax_[mid], ay_[mid]),
                arrowprops=dict(arrowstyle="->", color=col, lw=1.8))

ax.plot(*PIVOT, "*", color=COL_PIV, ms=20, zorder=20, mec="white", mew=0.8,
        label="PIVOT (3150,2250)")
ax.annotate("PIVOT\n(3150, 2250)", xy=PIVOT,
            xytext=(PIVOT[0]-1200, PIVOT[1]+800),
            color=COL_PIV, fontsize=9, fontweight="bold",
            arrowprops=dict(arrowstyle="->", color=COL_PIV, lw=2))

# 600 right offset arrow
ax.annotate("", xy=(4200, -200), xytext=(4800, -200),
            arrowprops=dict(arrowstyle="<->", color="#58a6ff", lw=2))
ax.text(4500, -310, "600", ha="center", color="#58a6ff", fontsize=10, fontweight="bold")

# 600 top offset arrow
ax.annotate("", xy=(-200, 0), xytext=(-200, 600),
            arrowprops=dict(arrowstyle="<->", color=COL_GOLD, lw=2))
ax.text(-320, 300, "600", ha="center", color=COL_GOLD, fontsize=10,
        fontweight="bold", rotation=90)

ax.set_xlim(*XLIM); ax.set_ylim(*YLIM)
ax.set_aspect("equal"); ax.invert_yaxis()
ax.legend(loc="lower left", facecolor="#21262d", edgecolor="#30363d",
          labelcolor="#c9d1d9", fontsize=7.5, ncol=2)

# ── Panel 2: Sweep ghost frames ────────────────────────────────────────────────
ax = axes[1]
style(ax, "Swept Motion  0°→90°CW\n(Ghost Frames, Plasma colormap)")

draw_rect(ax, A_corners, COL_A, COL_A, alpha=0.15, lw=3)
ax.text(2400, 1650, "A", ha="center", va="center",
        color="white", fontsize=16, fontweight="bold", alpha=0.4)

cmap = plt.cm.plasma
N = 20
for i, ang in enumerate(np.linspace(0, 90, N)):
    t = i / (N-1)
    ci = rot_angle(B_start, PIVOT, ang)
    patch = MplPoly(ci, closed=True, fc=cmap(t), ec=cmap(t),
                    alpha=0.06 + 0.22*t, lw=0.8 + 1.5*t, zorder=3+i)
    ax.add_patch(patch)

draw_rect(ax, B_start, COL_B,    "#ff6600", alpha=0.55, lw=3, zorder=25, label="Start (0°)")
draw_rect(ax, B_final, "#44ff88","#44ff88", alpha=0.45, lw=3, zorder=26, label="Final (90°CW)")

# Largest arc (BL corner)
bx, by = arcs[3]
ax.plot(bx, by, color=COL_GOLD, lw=2.5, alpha=0.9,
        label=f"BL arc  r={radii[3]:.0f}")
mid = len(bx)//2
ax.annotate("", xy=(bx[mid+4], by[mid+4]), xytext=(bx[mid], by[mid]),
            arrowprops=dict(arrowstyle="->", color=COL_GOLD, lw=2.5))

ax.plot(*PIVOT, "*", color=COL_PIV, ms=20, zorder=30, mec="white", mew=0.8)
ax.text(PIVOT[0]+200, PIVOT[1]-400, "PIVOT\n(2855, 1955)",
        color=COL_PIV, fontsize=9, fontweight="bold")

ax.set_xlim(*XLIM); ax.set_ylim(*YLIM)
ax.set_aspect("equal"); ax.invert_yaxis()
ax.legend(loc="lower left", facecolor="#21262d", edgecolor="#30363d",
          labelcolor="#c9d1d9", fontsize=9)

sm = plt.cm.ScalarMappable(cmap=cmap, norm=plt.Normalize(0, 90))
sm.set_array([])
cbar = plt.colorbar(sm, ax=ax, orientation="horizontal", pad=0.06, shrink=0.7)
cbar.set_label("Rotation (°)", color="#8b949e", fontsize=9)
cbar.ax.tick_params(colors="#8b949e")

# ── Panel 3: Key frames + forward/return arrows ────────────────────────────────
ax = axes[2]
style(ax, "Key Frames 0°→90°  |  Forward & Return Arc")

draw_rect(ax, A_corners, COL_A, COL_A, alpha=0.12, lw=2.5)

key_angles = [0, 15, 30, 45, 60, 75, 90]
for ang in key_angles:
    t = ang / 90
    color = plt.cm.RdYlGn(t)
    ci = rot_angle(B_start, PIVOT, ang)
    patch = MplPoly(ci, closed=True, fc=color, ec="white", alpha=0.3, lw=1.5)
    ax.add_patch(patch)
    ctr = ci.mean(axis=0)
    ax.text(ctr[0], ctr[1], f"{ang}°", ha="center", va="center",
            color="white", fontsize=8, fontweight="bold")

ax.plot(*PIVOT, "*", color=COL_PIV, ms=20, zorder=20, mec="white", mew=0.8)
ax.text(PIVOT[0]+200, PIVOT[1]-400, "PIVOT\n(3150,2250)",
        color=COL_PIV, fontsize=9, fontweight="bold")

# Forward arc arrow (BL corner)
bx, by = arcs[3]
ax.plot(bx, by, color=COL_GOLD, lw=3, alpha=0.9,
        label=f"BL arc  r={radii[3]:.0f}  (fwd CW)")
mid = len(bx)//3
ax.annotate("", xy=(bx[mid+4], by[mid+4]), xytext=(bx[mid], by[mid]),
            arrowprops=dict(arrowstyle="->", color=COL_GOLD, lw=2.5))

# Return arc arrow (CCW, same arc reversed)
mid2 = 2*len(bx)//3
ax.annotate("", xy=(bx[mid2-4], by[mid2-4]), xytext=(bx[mid2], by[mid2]),
            arrowprops=dict(arrowstyle="->", color="#a29bfe", lw=2.5))
ax.plot([], [], color="#a29bfe", lw=2.5, label="Return (CCW)")

ax.set_xlim(*XLIM); ax.set_ylim(*YLIM)
ax.set_aspect("equal"); ax.invert_yaxis()
ax.legend(loc="lower left", facecolor="#21262d", edgecolor="#30363d",
          labelcolor="#c9d1d9", fontsize=9)

plt.tight_layout(rect=[0, 0, 1, 0.95])
out2 = os.path.join(OUT_DIR, "rotation_analysis.png")
plt.savefig(out2, dpi=150, bbox_inches="tight", facecolor=DARK_BG)
print(f"Saved → rotation_analysis.png")

# ══════════════════════════════════════════════════════════════════════════════
# FIGURE 3 — Detailed arc sweep (step-by-step frames)
# ══════════════════════════════════════════════════════════════════════════════
fig3, ax3 = plt.subplots(figsize=(12, 11), facecolor=DARK_BG)
ax3.set_facecolor(PANEL_BG)
ax3.set_title(
    "Full Arc Sweep  —  All 4 corner arcs  ·  Pivot (3150, 2250)",
    fontsize=13, color="#e6edf3", pad=10
)

draw_rect(ax3, A_corners, COL_A, COL_A, alpha=0.2, lw=3, label="Rect A (fixed)")

N2 = 12
for i, ang in enumerate(np.linspace(0, 90, N2)):
    t = i / (N2-1)
    ci = rot_angle(B_start, PIVOT, ang)
    alpha_v = 0.08 + 0.35*t
    lw_v    = 0.8  + 2.0*t
    col     = plt.cm.plasma(t)
    patch = MplPoly(ci, closed=True, fc=col, ec=col, alpha=alpha_v, lw=lw_v, zorder=3+i)
    ax3.add_patch(patch)

for (ax_, ay_), lbl, col, r in zip(arcs, ["TL","TR","BR","BL"], arc_cols, radii):
    ax3.plot(ax_, ay_, color=col, lw=2.5, ls=":", alpha=0.95,
             label=f"{lbl} corner  r={r:.0f}")
    mid = len(ax_)//2
    ax3.annotate("", xy=(ax_[mid+5], ay_[mid+5]), xytext=(ax_[mid], ay_[mid]),
                 arrowprops=dict(arrowstyle="->", color=col, lw=2))

draw_rect(ax3, B_start, COL_B, "#ff6600", alpha=0.6, lw=3, ls="--", zorder=20,
          label="B start (0°)")
draw_rect(ax3, B_final, "#44ff88","#44ff88", alpha=0.5, lw=3, zorder=21,
          label="B final (90°CW)")

ax3.plot(*PIVOT, "*", color=COL_PIV, ms=24, zorder=30, mec="white", mew=1,
         label="PIVOT (3150, 2250)")
ax3.annotate("PIVOT\n(3150, 2250)", xy=PIVOT,
             xytext=(PIVOT[0]-1400, PIVOT[1]+700),
             color=COL_PIV, fontsize=11, fontweight="bold",
             arrowprops=dict(arrowstyle="->", color=COL_PIV, lw=2.5))

ax3.set_xlim(*XLIM); ax3.set_ylim(*YLIM)
ax3.set_aspect("equal"); ax3.invert_yaxis()
ax3.set_xlabel("X", color="#8b949e"); ax3.set_ylabel("Y", color="#8b949e")
for sp in ax3.spines.values(): sp.set_edgecolor("#30363d")
ax3.tick_params(colors="#8b949e", labelsize=8)
ax3.legend(facecolor="#21262d", edgecolor="#30363d", labelcolor="#c9d1d9",
           fontsize=9, loc="lower left")

plt.tight_layout()
out3 = os.path.join(OUT_DIR, "arc_sweep.png")
plt.savefig(out3, dpi=150, bbox_inches="tight", facecolor=DARK_BG)
print(f"Saved → arc_sweep.png")

plt.show()

# ─── FINAL SUMMARY ────────────────────────────────────────────────────────────
print()
print("=" * 60)
print("FINAL ANSWER")
print("=" * 60)
print(f"""
Rect A (fixed, landscape, BLUE):
  (0,0) → (4800,3300)  — 4800×3300

Rect B FINAL position (portrait, ORANGE):
  ({B_fx0},{B_fy0}) → ({B_fx1},{B_fy1})  — 3300×4800
  ✓ Right edge = {B_fx1} = 4800 − 600   (600 inside A right)
  ✓ Top  edge  = {B_fy0} = 0   + 600   (600 below A top)

PIVOT (exact, unique): (3150, 2250)
  Sits inside Rect A and inside Rect B start position.

ARC RADII per corner:
  TL (0,    0   ) → {radii[0]:8.2f}
  TR (4800, 0   ) → {radii[1]:8.2f}
  BR (4800, 3300) → {radii[2]:8.2f}
  BL (0,    3300) → {radii[3]:8.2f}  ← largest sweep

MOTION: 90° CLOCKWISE rotation about (3150, 2250)
RETURN: 90° COUNTER-CLOCKWISE about the same pivot

IMAGES SAVED:
  final_position.png   — matches your reference image
  rotation_analysis.png — 3-panel: arcs, sweep, key frames
  arc_sweep.png        — all 4 corner arcs detailed
""")
