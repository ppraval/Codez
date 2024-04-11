#include<bits/stdc++.h>
using namespace std;

int minKey(int vertices, vector<int> key, vector<bool>& curr_mst)
{
    int min = INT_MAX;
    int min_index;
    for(int v = 0; v < vertices; v++)
    {
        if(curr_mst[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void mst(int vertices, int vertex, vector<vector<int>> graph)
{
    vector<bool> curr_mst(vertices, false);
    vector<int> key(vertices, INT_MAX);
    vector<int> parent(vertices);

    key[vertex] = 0;
    parent[vertex] = -1;

    for(int count = 0; count < vertices - 1; count++)
    {
        int u = minKey(vertices, key, curr_mst);
        curr_mst[u] = true;
        for(int v = 0; v < vertices; v++)
        {
            if(graph[u][v] && curr_mst[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int weight = accumulate(key.begin(), key.end(), 0);
    cout << weight << endl;
}

int main()
{
    int vertices = 5;
    vector<vector<int>> adj_matrix = {
        {0, 1, 5, 0, 0},
        {1, 0, 2, 0, 0},
        {5, 2, 0, 3, 6},
        {0, 0, 3, 0, 4},
        {0, 0, 6, 4, 0}
    };
    mst(vertices, 1, adj_matrix);
    return 0;
}