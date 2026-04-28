"""
TWO SYMMETRIC RECTANGLES — find INNER pivot for outward rotation
=================================================================

Setup (screen coords, y DOWN):
  Each rect:  W × H = 13620 × 3830  (landscape)
  Left  rect: x ∈ [-W, 0], y ∈ [0, H]   ← shares vertical edge x=0 with right
  Right rect: x ∈ [ 0, W], y ∈ [0, H]

Both rotate OUTWARD simultaneously (mirror motion):
  Right rect rotates CCW (screen)  → bottom-out swings east + south
  Left  rect rotates CW  (screen)  → mirror

Constraint:
  By symmetry, left rect = mirror(right rect) about x=0 at all times.
  Two mirror-image convex sets overlap iff right rect has any point with x < 0.
  → Constraint: right rect stays in  x ≥ 0  for every angle θ ∈ [0, θ_max].

Goal: most "inner" pivot (px, py) inside right rect satisfying this.

Analytical result:
  Right rect's TL corner = (0,0). Under CCW screen rotation by θ about (px,py):
      x_TL(θ) = px(1 − cos θ) − py · sin θ
  This has interior minimum at θ* = atan2(py, px), where
      x_TL(θ*) = px − √(px² + py²)   < 0   for any py > 0
  → For ANY rotation angle θ_max ≥ θ*, only py = 0 is feasible.
  → For 90° rotation, θ* ≤ 90° always (when py > 0), so py MUST be 0.

  ⇒  Most-internal pivot on the top edge: (px, py) = (W/2, 0)
     This is centered on the shared edge, max distance from L/R corners.

For SMALLER rotation angles a truly interior pivot is possible:
  Constraint at boundary θ_max:  py ≤ px · tan(θ_max / 2)
  AND no interior critical point in range:  py ≥ px · tan(θ_max)
  Combined ⇒ feasible only if py = 0  (since tan(θ/2) < tan(θ) for θ ∈ (0,π/2))
  Same conclusion for any θ_max > 0.
"""

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.patches import Polygon as MplPoly
import os, warnings
warnings.filterwarnings("ignore")

OUT_DIR = os.path.dirname(os.path.abspath(__file__))

# ─── DIMENSIONS ───────────────────────────────────────────────────────────────
W = 13620.0
H = 3830.0
ROT_DEG = 90.0          # outward rotation amount

# ─── GEOMETRY ─────────────────────────────────────────────────────────────────
right_rect = np.array([[0,0],[W,0],[W,H],[0,H]], dtype=float)
left_rect  = np.array([[-W,0],[0,0],[0,H],[-W,H]], dtype=float)

def rotate_pts(pts, pivot, deg, direction="ccw"):
    """Rotate pts about pivot. CCW = positive in y-down screen coords."""
    a = np.deg2rad(deg) * (1 if direction == "ccw" else -1)
    px, py = pivot
    dx = pts[:, 0] - px
    dy = pts[:, 1] - py
    # CCW screen: x' = px + dx cos a + dy sin a
    #             y' = py − dx sin a + dy cos a
    rx = px + dx*np.cos(a) + dy*np.sin(a)
    ry = py - dx*np.sin(a) + dy*np.cos(a)
    return np.column_stack([rx, ry])

def min_x_during_rotation(pivot, max_deg, n=361):
    """Minimum x reached by any corner of the right rect during rotation."""
    angs = np.linspace(0, max_deg, n)
    mn = np.inf
    worst_ang = 0.0
    for a in angs:
        rot = rotate_pts(right_rect, pivot, a, "ccw")
        m = rot[:, 0].min()
        if m < mn:
            mn = m
            worst_ang = a
    return mn, worst_ang

def is_safe(pivot, max_deg, tol=1e-6):
    return min_x_during_rotation(pivot, max_deg)[0] >= -tol

# ─── ANALYTICAL: max py allowed for given px and rotation ─────────────────────
def max_py_for_px(px, max_deg):
    """Largest py ≥ 0 such that x_TL(θ) ≥ 0 for all θ ∈ [0, max_deg]."""
    # Three cases:
    #   - py = 0 always works
    #   - For py > 0, need (a) θ* = atan(py/px) > max_deg  AND
    #                     (b) py ≤ px tan(max_deg/2)
    #   - These are incompatible ⇒ only py = 0 works
    # Binary search numerically as a confirmation.
    if px <= 0: return 0.0
    lo, hi = 0.0, H
    for _ in range(60):
        mid = 0.5*(lo+hi)
        if is_safe((px, mid), max_deg, tol=1e-3):
            lo = mid
        else:
            hi = mid
    return lo

# ─── SEARCH FOR MOST-INTERNAL VALID PIVOT ─────────────────────────────────────
print("=" * 65)
print(f"PROBLEM: two {W:.0f} × {H:.0f} rects side-by-side, outward {ROT_DEG:.0f}° rotation")
print("=" * 65)

# Sample max_py over px range
sample_px = np.linspace(0.05*W, 0.95*W, 25)
sample_py = [max_py_for_px(px, ROT_DEG) for px in sample_px]

print(f"\nNumerical search: max safe py at sample px values (rot={ROT_DEG}°)")
for px, py in zip(sample_px[::5], sample_py[::5]):
    print(f"  px = {px:8.1f}  →  max py = {py:8.4f}")

print("\n→ All max_py ≈ 0, confirming analytical result:")
print("  PIVOT MUST LIE ON THE TOP (NORTH) EDGE  (py = 0)")

# Most internal pivot on top edge = centered (max distance from L & R corners)
PIVOT_R = (W/2, 0.0)             # right rect pivot
PIVOT_L = (-W/2, 0.0)            # left rect pivot (mirror)

mn, ang = min_x_during_rotation(PIVOT_R, ROT_DEG)
print(f"\nCHOSEN pivot for right rect : ({PIVOT_R[0]:.1f}, {PIVOT_R[1]:.1f})  [centered on top edge]")
print(f"        pivot for left  rect : ({PIVOT_L[0]:.1f}, {PIVOT_L[1]:.1f})  [mirror]")
print(f"  min x during rotation: {mn:.4f}  (worst at θ ≈ {ang:.1f}°)  →  no overlap ✓")

# Try a few smaller angles to see if any internal py becomes feasible
print(f"\nFor reference — max py allowed at px=W/2 = {W/2:.0f} for various rotations:")
for ang_test in [10, 30, 45, 60, 90, 120, 180]:
    pyv = max_py_for_px(W/2, ang_test)
    print(f"  rot = {ang_test:4.0f}°  →  max py = {pyv:8.4f}  (effectively 0)")

# ─── ARC TRACES (the four corners of the right rect) ──────────────────────────
def corner_arc(corner, pivot, deg, direction="ccw", n=400):
    angs = np.linspace(0, deg, n)
    pts = np.array([rotate_pts(corner[None,:], pivot, a, direction)[0] for a in angs])
    return pts[:, 0], pts[:, 1]

right_arcs = [corner_arc(c, PIVOT_R, ROT_DEG, "ccw") for c in right_rect]
left_arcs  = [corner_arc(c, PIVOT_L, ROT_DEG, "cw")  for c in left_rect]
corner_names = ["TL", "TR", "BR", "BL"]
arc_cols = ["#ff9ff3", "#ffeaa7", "#74b9ff", "#a29bfe"]

# ─── DRAW ─────────────────────────────────────────────────────────────────────
DARK_BG  = "#0d1117"
PANEL_BG = "#161b22"
COL_R    = "#e07b39"   # right rect orange
COL_L    = "#1d6fa4"   # left rect blue
COL_PIV  = "#ff4444"
COL_GOLD = "#ffd700"

def draw_rect(ax, corners, fc, ec, alpha=0.4, lw=2.5, ls="-", zorder=2, label=None):
    ax.add_patch(MplPoly(corners, closed=True, fc=fc, ec=ec,
                         alpha=alpha, lw=lw, ls=ls, zorder=zorder, label=label))

def style_ax(ax, title):
    ax.set_facecolor(PANEL_BG)
    ax.set_title(title, color="#c9d1d9", fontsize=11, pad=8)
    for sp in ax.spines.values(): sp.set_edgecolor("#30363d")
    ax.tick_params(colors="#8b949e", labelsize=8)
    ax.set_xlabel("X", color="#8b949e"); ax.set_ylabel("Y", color="#8b949e")

# Limits chosen to fit the full sweep (radius up to √((W/2)²+H²+...) etc.)
R_MAX = max(np.hypot(c[0]-PIVOT_R[0], c[1]-PIVOT_R[1]) for c in right_rect)
print(f"\nLargest swept radius (BR/BL corner): {R_MAX:.1f}")

XLIM = (-R_MAX*1.1, R_MAX*1.1)
YLIM = (-R_MAX*0.15, R_MAX*1.1)

fig, axes = plt.subplots(1, 3, figsize=(26, 11), facecolor=DARK_BG)
fig.suptitle(
    f"Two {W:.0f}×{H:.0f} rects · outward {ROT_DEG:.0f}° rotation · "
    f"Pivots on shared TOP edge at (±{W/2:.0f}, 0)  ·  no overlap",
    fontsize=14, color="#e6edf3", fontweight="bold", y=0.98
)

# ── Panel 1: Start + Final + Pivots + corner arcs ──────────────────────────────
ax = axes[0]
style_ax(ax, "Start (top) → Final (90° outward) · Corner arcs")

# Start positions
draw_rect(ax, left_rect,  COL_L, COL_L, alpha=0.25, lw=2.5, ls="--", label="Left start")
draw_rect(ax, right_rect, COL_R, COL_R, alpha=0.25, lw=2.5, ls="--", label="Right start")

# Final positions
right_final = rotate_pts(right_rect, PIVOT_R, ROT_DEG, "ccw")
left_final  = rotate_pts(left_rect,  PIVOT_L, ROT_DEG, "cw")
draw_rect(ax, right_final, COL_R, "#ff7700", alpha=0.55, lw=3, label="Right final")
draw_rect(ax, left_final,  COL_L, "#0d5a8a", alpha=0.55, lw=3, label="Left final")

# Right rect corner arcs
for (xs, ys), nm, col in zip(right_arcs, corner_names, arc_cols):
    ax.plot(xs, ys, color=col, lw=1.8, ls=":", alpha=0.9, label=f"R-{nm} arc")
# Left mirror arcs (lighter)
for (xs, ys), col in zip(left_arcs, arc_cols):
    ax.plot(xs, ys, color=col, lw=1.2, ls=":", alpha=0.5)

# Pivots
ax.plot(*PIVOT_R, "*", color=COL_PIV, ms=20, zorder=20, mec="white", mew=0.8,
        label=f"R pivot ({PIVOT_R[0]:.0f}, {PIVOT_R[1]:.0f})")
ax.plot(*PIVOT_L, "*", color=COL_PIV, ms=20, zorder=20, mec="white", mew=0.8,
        label=f"L pivot ({PIVOT_L[0]:.0f}, {PIVOT_L[1]:.0f})")

# Centerline
ax.axvline(0, color="#666", lw=0.8, ls="-.", alpha=0.6)

ax.set_xlim(*XLIM); ax.set_ylim(*YLIM)
ax.set_aspect("equal"); ax.invert_yaxis()
ax.legend(loc="lower right", facecolor="#21262d", edgecolor="#30363d",
          labelcolor="#c9d1d9", fontsize=7.5, ncol=2)

# ── Panel 2: Sweep ghost frames (both rects) ──────────────────────────────────
ax = axes[1]
style_ax(ax, f"Swept Motion 0° → {ROT_DEG:.0f}° (ghost frames)")

cmap = plt.cm.plasma
N = 18
for i, ang in enumerate(np.linspace(0, ROT_DEG, N)):
    t = i/(N-1)
    rR = rotate_pts(right_rect, PIVOT_R, ang, "ccw")
    rL = rotate_pts(left_rect,  PIVOT_L, ang, "cw")
    a_v = 0.05 + 0.22*t
    lw_v = 0.6 + 1.5*t
    ax.add_patch(MplPoly(rR, closed=True, fc=cmap(t), ec=cmap(t),
                         alpha=a_v, lw=lw_v, zorder=3+i))
    ax.add_patch(MplPoly(rL, closed=True, fc=cmap(t), ec=cmap(t),
                         alpha=a_v, lw=lw_v, zorder=3+i))

# Bold start & final
draw_rect(ax, right_rect, COL_R, "#ff6600", alpha=0.5, lw=2.5, zorder=24, label="Start")
draw_rect(ax, left_rect,  COL_L, "#0d5a8a", alpha=0.5, lw=2.5, zorder=24)
draw_rect(ax, right_final, "#44ff88", "#44ff88", alpha=0.4, lw=2.5, zorder=25, label="Final")
draw_rect(ax, left_final,  "#44ff88", "#44ff88", alpha=0.4, lw=2.5, zorder=25)

# Largest arc on each side
xs, ys = right_arcs[2]   # BR corner
ax.plot(xs, ys, color=COL_GOLD, lw=2.5, alpha=0.9, label=f"R-BR arc r={R_MAX:.0f}")
xs, ys = left_arcs[3]    # BL of left = mirror of BR right
ax.plot(xs, ys, color=COL_GOLD, lw=2.5, alpha=0.9)

ax.plot(*PIVOT_R, "*", color=COL_PIV, ms=18, zorder=30, mec="white", mew=0.8)
ax.plot(*PIVOT_L, "*", color=COL_PIV, ms=18, zorder=30, mec="white", mew=0.8)
ax.axvline(0, color="#666", lw=0.8, ls="-.", alpha=0.6)

ax.set_xlim(*XLIM); ax.set_ylim(*YLIM)
ax.set_aspect("equal"); ax.invert_yaxis()
ax.legend(loc="lower right", facecolor="#21262d", edgecolor="#30363d",
          labelcolor="#c9d1d9", fontsize=8)

sm = plt.cm.ScalarMappable(cmap=cmap, norm=plt.Normalize(0, ROT_DEG))
sm.set_array([])
cbar = plt.colorbar(sm, ax=ax, orientation="horizontal", pad=0.07, shrink=0.7)
cbar.set_label("Rotation (°)", color="#8b949e", fontsize=9)
cbar.ax.tick_params(colors="#8b949e")

# ── Panel 3: feasibility heatmap ──────────────────────────────────────────────
ax = axes[2]
style_ax(ax, f"Pivot feasibility map (right rect)\n"
             f"green = safe at {ROT_DEG:.0f}° rotation, red = collides")

NX, NY = 60, 30
pxs = np.linspace(0, W, NX)
pys = np.linspace(0, H, NY)
grid = np.zeros((NY, NX))
for i, py in enumerate(pys):
    for j, px in enumerate(pxs):
        mn, _ = min_x_during_rotation((px, py), ROT_DEG, n=91)
        grid[i, j] = mn   # ≥0 safe, <0 collision

# Plot the rect itself for reference
draw_rect(ax, right_rect, "none", "white", alpha=1.0, lw=2)
im = ax.imshow(grid, extent=[0, W, H, 0], origin="upper",
               cmap="RdYlGn", aspect="auto",
               vmin=-W, vmax=W*0.05)
ax.contour(pxs, pys, grid, levels=[0], colors=["white"], linewidths=2)
# Mark the chosen pivot
ax.plot(*PIVOT_R, "*", color="cyan", ms=22, mec="white", mew=1.2, zorder=20,
        label=f"Chosen pivot (W/2, 0)")
# top edge highlight
ax.plot([0, W], [0, 0], color="lime", lw=3.5, alpha=0.9, label="Safe locus (top edge)")

ax.set_xlim(0, W); ax.set_ylim(H, 0)
ax.set_aspect("auto")
ax.legend(loc="lower right", facecolor="#21262d", edgecolor="#30363d",
          labelcolor="#c9d1d9", fontsize=9)

cb = plt.colorbar(im, ax=ax, orientation="horizontal", pad=0.07, shrink=0.7)
cb.set_label("min x of right rect during rotation  (≥0 = safe)",
             color="#8b949e", fontsize=9)
cb.ax.tick_params(colors="#8b949e")

plt.tight_layout(rect=[0, 0, 1, 0.95])
out1 = os.path.join(OUT_DIR, "two_rects_rotation.png")
plt.savefig(out1, dpi=140, bbox_inches="tight", facecolor=DARK_BG)
print(f"\nSaved → two_rects_rotation.png")

# ─── FIGURE 2: Clean reference-style image (white bg) ─────────────────────────
fig2, ax2 = plt.subplots(figsize=(13, 10), facecolor="white")
ax2.set_facecolor("white")
ax2.set_title(
    f"Two symmetric rects {W:.0f}×{H:.0f}  ·  outward 90° rotation about top-edge centers\n"
    f"Pivots at (±{W/2:.0f}, 0)  —  most-internal collision-free locations",
    fontsize=11, color="#222", pad=10
)

# Start rects (light)
draw_rect(ax2, left_rect,  "#cce0ee", "#1d6fa4", alpha=0.6, lw=2)
draw_rect(ax2, right_rect, "#f3d4b5", "#c06020", alpha=0.6, lw=2)

# Final rects
draw_rect(ax2, left_final,  "#1d6fa4", "#0d5a8a", alpha=0.55, lw=2.5)
draw_rect(ax2, right_final, "#e07b39", "#c06020", alpha=0.55, lw=2.5)

# All four corner arcs (right) and mirrors (left)
for (xs, ys), nm, col in zip(right_arcs, corner_names, ["#d63031","#fdcb6e","#0984e3","#6c5ce7"]):
    ax2.plot(xs, ys, color=col, lw=1.5, ls=":", alpha=0.85, label=f"R-{nm} arc r={np.hypot(*np.subtract(right_rect[corner_names.index(nm)], PIVOT_R)):.0f}")
for xs, ys in left_arcs:
    pass  # skip duplicate labels

ax2.plot(*PIVOT_R, "*", color="red", ms=20, zorder=20, mec="white", mew=1)
ax2.plot(*PIVOT_L, "*", color="red", ms=20, zorder=20, mec="white", mew=1)
ax2.annotate(f"R pivot\n({PIVOT_R[0]:.0f}, 0)", xy=PIVOT_R, xytext=(PIVOT_R[0]+1500, -1500),
             color="red", fontsize=10, fontweight="bold",
             arrowprops=dict(arrowstyle="->", color="red", lw=1.5))
ax2.annotate(f"L pivot\n({PIVOT_L[0]:.0f}, 0)", xy=PIVOT_L, xytext=(PIVOT_L[0]-3500, -1500),
             color="red", fontsize=10, fontweight="bold",
             arrowprops=dict(arrowstyle="->", color="red", lw=1.5))

ax2.axvline(0, color="#888", lw=0.8, ls="-.", alpha=0.6, label="Symmetry axis (no crossing)")

ax2.set_xlim(*XLIM); ax2.set_ylim(*YLIM)
ax2.set_aspect("equal"); ax2.invert_yaxis()
ax2.set_xlabel("X (units)"); ax2.set_ylabel("Y (units)")
ax2.grid(True, color="#ddd", alpha=0.5)
ax2.legend(loc="lower right", fontsize=8)

plt.tight_layout()
out2 = os.path.join(OUT_DIR, "two_rects_clean.png")
plt.savefig(out2, dpi=140, bbox_inches="tight", facecolor="white")
print(f"Saved → two_rects_clean.png")

plt.show()

# ─── FINAL ANSWER ─────────────────────────────────────────────────────────────
print()
print("=" * 65)
print("FINAL ANSWER")
print("=" * 65)
print(f"""
Rect dimensions     : {W:.0f} × {H:.0f}  (each)
Configuration       : side-by-side, sharing edge at x = 0
Outward rotation    : {ROT_DEG:.0f}°  (right CCW screen, left CW screen, mirrored)

PIVOT for RIGHT rect : ( {PIVOT_R[0]:8.1f} , {PIVOT_R[1]:.1f} )   = (W/2, 0)
PIVOT for LEFT  rect : ( {PIVOT_L[0]:8.1f} , {PIVOT_L[1]:.1f} )   = (−W/2, 0)

Both pivots lie on the SHARED TOP (north) EDGE.

  → No internal py > 0 is collision-free for any positive rotation.
  → On the top edge, ALL px ∈ [0, W] are safe — chose px = W/2 as
    the most-central (max distance from outer corners).

Largest sweep radius (BR / BL outer-bottom corner): {R_MAX:.1f}
  → That corner traces an arc of radius ≈ √((W/2)² + H²)
                                       = √({(W/2)**2:.0f} + {H**2:.0f})
                                       = {np.hypot(W/2, H):.1f}

Images:
  two_rects_rotation.png  —  3 panels: arcs · sweep · feasibility heatmap
  two_rects_clean.png     —  reference-style overlay
""")
