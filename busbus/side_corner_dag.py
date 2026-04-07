"""
Side & Corner DAG
=================
Requirements:
    pip install networkx matplotlib

Run:
    python dag.py
"""

import matplotlib
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import networkx as nx

# ── Edge data ─────────────────────────────────────────────────────────────────
SIDE_EDGES = [
    ("Pranav",   "Praval"),
    ("Pranav",   "Varshid"),
    ("Pranav",   "Shiva"),
    ("Pranav",   "Ganadeep"),
    ("Karthik",  "Praval"),
    ("Sameer",   "Praval"),
    ("Shiva",    "Praval"),
    ("Ganadeep", "Praval"),
    ("Varshid",  "Praval"),
    ("Vivek",    "Praval"),
    ("Pavan",    "Praval"),
]

CORNER_EDGES = [
    ("Karthik",  "Pranav"),
    ("Sameer",   "Pranav"),
    ("Sameer",   "Shiva"),
    ("Sameer",   "Vivek"),
    ("Shiva",    "Pranav"),
    ("Shiva",    "Pavan"),
    ("Shiva",    "Vivek"),
    ("Shiva",    "Karthik"),
    ("Ganadeep", "Pranav"),
    ("Ganadeep", "Karthik"),
    ("Praval",   "Pranav"),
    ("Varshid",  "Pranav"),
    ("Varshid",  "Karthik"),
    ("Vivek",    "Pranav"),
    ("Vivek",    "Karthik"),
    ("Vivek",    "Ganadeep"),
    ("Vivek",    "Pavan"),
    ("Vivek",    "Shiva"),
    ("Vivek",    "Sameer"),
    ("Pavan",    "Pranav"),
    ("Pavan",    "Vivek"),
    ("Pavan",    "Karthik"),
]

ALL_NODES = [
    "Pranav", "Karthik", "Sameer", "Pavan",
    "Shiva", "Vivek", "Ganadeep", "Praval", "Varshid", "Manoj",
]

# ── Build graph ────────────────────────────────────────────────────────────────
G = nx.MultiDiGraph()
G.add_nodes_from(ALL_NODES)

for u, v in SIDE_EDGES:
    G.add_edge(u, v, kind="side")

for u, v in CORNER_EDGES:
    G.add_edge(u, v, kind="corner")

# ── Layout ─────────────────────────────────────────────────────────────────────
# Hand-tuned positions so the graph mirrors the original visual
pos = {
    "Pranav":   (0.30, 0.90),
    "Karthik":  (0.55, 0.90),
    "Sameer":   (0.80, 0.90),
    "Shiva":    (0.10, 0.65),
    "Praval":   (0.50, 0.50),
    "Varshid":  (0.75, 0.65),
    "Pavan":    (0.10, 0.35),
    "Ganadeep": (0.35, 0.35),
    "Vivek":    (0.80, 0.35),
    "Manoj":    (0.10, 0.10),
}

# ── Colours ────────────────────────────────────────────────────────────────────
SIDE_COLOR   = "#1D9E75"   # teal
CORNER_COLOR = "#7F77DD"   # purple

NODE_COLOR_DEFAULT    = "#9FE1CB"  # teal-100
NODE_COLOR_SINK       = "#F5C4B3"  # coral-100  (Praval — primary Side sink)
NODE_COLOR_TARGETONLY = "#D3D1C7"  # gray-100   (Pavan — only a corner target)
NODE_COLOR_ISOLATED   = "#D3D1C7"  # gray-100   (Manoj)

node_colors = []
for n in G.nodes():
    if n == "Praval":
        node_colors.append(NODE_COLOR_SINK)
    elif n == "Manoj":
        node_colors.append(NODE_COLOR_TARGETONLY)
    else:
        node_colors.append(NODE_COLOR_DEFAULT)

# ── Draw ───────────────────────────────────────────────────────────────────────
fig, ax = plt.subplots(figsize=(13, 10))
ax.set_facecolor("#FAFAF8")
fig.patch.set_facecolor("#FAFAF8")
ax.set_title("Side & Corner DAG", fontsize=15, fontweight="500", pad=14,
             color="#2C2C2A")

# Nodes
nx.draw_networkx_nodes(
    G, pos,
    node_color=node_colors,
    node_size=2200,
    linewidths=1.2,
    edgecolors="#888780",
    ax=ax,
)
nx.draw_networkx_labels(
    G, pos,
    font_size=9,
    font_weight="500",
    font_color="#2C2C2A",
    ax=ax,
)

# ── Separate edge lists ────────────────────────────────────────────────────────
side_edges   = [(u, v) for u, v, d in G.edges(data=True) if d["kind"] == "side"]
corner_edges = [(u, v) for u, v, d in G.edges(data=True) if d["kind"] == "corner"]

# Side edges — solid teal, slight left curve
nx.draw_networkx_edges(
    G, pos,
    edgelist=side_edges,
    edge_color=SIDE_COLOR,
    width=1.8,
    arrows=True,
    arrowstyle="-|>",
    arrowsize=18,
    connectionstyle="arc3,rad=0.10",
    min_source_margin=22,
    min_target_margin=22,
    ax=ax,
)

# Corner edges — dashed purple, opposite curve so they don't overlap
nx.draw_networkx_edges(
    G, pos,
    edgelist=corner_edges,
    edge_color=CORNER_COLOR,
    width=1.4,
    style="dashed",
    arrows=True,
    arrowstyle="-|>",
    arrowsize=16,
    connectionstyle="arc3,rad=-0.20",
    min_source_margin=22,
    min_target_margin=22,
    ax=ax,
)

# ── Legend ─────────────────────────────────────────────────────────────────────
legend_handles = [
    mpatches.Patch(facecolor=NODE_COLOR_DEFAULT,    edgecolor="#888780", label="Active node"),
    mpatches.Patch(facecolor=NODE_COLOR_SINK,       edgecolor="#888780", label="Praval (Side sink)"),
    mpatches.Patch(facecolor=NODE_COLOR_TARGETONLY, edgecolor="#888780", label="Target-only / Isolated"),
    mpatches.Patch(color=SIDE_COLOR,   label="Side edge (solid)"),
    mpatches.Patch(color=CORNER_COLOR, label="Corner edge (dashed)", linestyle="--"),
]
ax.legend(
    handles=legend_handles,
    loc="lower right",
    fontsize=8,
    framealpha=0.85,
    edgecolor="#B4B2A9",
)

# ── Manoj label annotation ─────────────────────────────────────────────────────
ax.annotate(
    "disconnected",
    xy=pos["Manoj"],
    xytext=(pos["Manoj"][0] + 0.14, pos["Manoj"][1]),
    fontsize=7.5,
    color="#888780",
    va="center",
)

ax.axis("off")
plt.tight_layout()
plt.savefig("dag_output.png", dpi=150, bbox_inches="tight")
print("Saved → dag_output.png")
plt.show()
