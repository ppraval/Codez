#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFSUtil(int v, vector<bool>& visited, const vector<vector<int>>& adj, vector<int>& path, int dest) {
    visited[v] = true;
    path.push_back(v);

    if (v == dest) {
        for (int i = 0; i < path.size(); ++i) {
            if (i > 0) cout << " ";
            cout << path[i];
        }
        cout << endl;
    } else {
        for (int i : adj[v]) {
            if (!visited[i]) {
                DFSUtil(i, visited, adj, path, dest);
            }
        }
    }

    path.pop_back();
    visited[v] = false;
}

void allPaths(int src, int dest, const vector<vector<int>>& adj, int N) {
    vector<bool> visited(N, false);
    vector<int> path;
    DFSUtil(src, visited, adj, path, dest);
}

bool isCyclicUtil(int v, vector<bool>& visited, int parent, const vector<vector<int>>& adj) {
    visited[v] = true;

    for (int i : adj[v]) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, v, adj)) return true;
        } else if (i != parent) {
            return true;
        }
    }

    return false;
}

bool isValidTree(const vector<vector<int>>& adj, int N) {
    vector<bool> visited(N, false);

    if (isCyclicUtil(0, visited, -1, adj)) return false;

    for (bool v : visited) {
        if (!v) return false;
    }

    return true;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> adj(N);
    for (int i = 0; i < N; ++i) {
        int u;
        cin >> u;
        int v;
        while (cin >> v) {
            if (cin.peek() == '\n') break;
            adj[u].push_back(v);
        }
    }

    char command;
    while (cin >> command) {
        if (command == 'x') break;

        if (command == 'a') {
            int Node1, Node2;
            cin >> Node1 >> Node2;
            allPaths(Node1, Node2, adj, N);
        } else if (command == 't') {
            cout << (isValidTree(adj, N) ? 1 : -1) << endl;
        }
    }

    return 0;
}
