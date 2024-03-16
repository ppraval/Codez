#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& adj_list, int u, int v)
{
    adj_list[u].push_back(v);
}

void dfs(vector<vector<int>> adj_list, int v, vector<bool>& visited)
{
    visited[v] = true;
    cout << v << " ";
    for(int i = 0; i < adj_list[v].size(); i++)
    {
        if(visited[adj_list[v][i]] == false)
            dfs(adj_list, adj_list[v][i], visited);
    }
}


int main()
{
    int vertices = 5;
    vector<vector<int>> adj_list(vertices);
    vector<bool> visited (vertices, false);
    addEdge(adj_list, 0, 1);
    addEdge(adj_list, 0, 2);
    addEdge(adj_list, 0, 2);
    addEdge(adj_list, 2, 4);
    addEdge(adj_list, 2, 3);
    addEdge(adj_list, 3, 2);

    // addEdge(adj_list, 0, 1);
    // addEdge(adj_list, 0, 2);
    // addEdge(adj_list, 1, 2);
    // addEdge(adj_list, 2, 0);
    // addEdge(adj_list, 2, 3);
    // addEdge(adj_list, 3, 3);

    cout << "the DFS traversal of node 0 is" << " ";
    dfs(adj_list, 0, visited);
    return 0;
}