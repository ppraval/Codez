#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
    int u, v, cost;
};

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

bool compareCost(const Edge& a, const Edge& b) { return a.cost < b.cost; }

int main() {
    int n;
    cin >> n;

    vector<vector<int>> costMatrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> costMatrix[i][j];

    int m;
    cin >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;

    sort(edges.begin(), edges.end(), compareCost);

    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int minCost = 0;
    for (Edge e : edges) {
        int u = e.u;
        int v = e.v;
        int cost = e.cost;

        if (find(parent, u) != find(parent, v)) {
            minCost += cost;
            unionSets(parent, rank, u, v);
        }
    }

    cout << minCost << endl;

    return 0;
}
