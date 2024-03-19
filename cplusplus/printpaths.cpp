#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& adj_list, int u, int v)
{
    adj_list[u].push_back(v);
}

void dfs(vector<vector<int>> adj_list, int v, vector<bool>& visited, int end_node, vector<int>& path)
{
    visited[v] = true;
    path.push_back(v);
    if(v == end_node)
    {
        for(int j : path)
            cout << j << " ";
        cout << endl;
    }
    else
    {
        for(int i = 0; i < adj_list[v].size(); i++)
        {
            if(visited[adj_list[v][i]] == false)
                dfs(adj_list, adj_list[v][i], visited, end_node, path);
        }
    }
    path.pop_back();
    visited[v] = false;
}

void printPath(vector<vector<int>> adj_list, int start_node, int end_node, int vertices)
{
    vector<bool> visited (vertices, false);
    vector<int> path;
    dfs(adj_list, start_node, visited, end_node, path);
}


int main()
{
    int vertices = 6;
    vector<vector<int>> adj_list(vertices);
    vector<bool> visited (vertices, false);
    addEdge(adj_list, 0, 1);
    addEdge(adj_list, 0, 3);
    addEdge(adj_list, 0, 5);

    addEdge(adj_list, 1, 0);
    addEdge(adj_list, 1, 2);
    addEdge(adj_list, 1, 5);

    addEdge(adj_list, 2, 1);
    addEdge(adj_list, 2, 3);
    addEdge(adj_list, 2, 4);

    addEdge(adj_list, 3, 0);
    addEdge(adj_list, 3, 2);

    addEdge(adj_list, 4, 2);
    addEdge(adj_list, 5, 0);
    addEdge(adj_list, 5, 1);

    cout << "the path from node 1 to 4 is/are" << endl;
    printPath(adj_list, 0, 1, vertices);
    return 0;
}