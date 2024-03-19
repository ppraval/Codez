#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& adj_list, int u, int v)
{
    adj_list[u].push_back(v);
}

int dfs(vector<vector<int>> adj_list, int v, vector<bool>& visited, int parent)
{
    visited[v] = true;
    for(int i = 0; i < adj_list[v].size(); i++)
    {
        if(visited[adj_list[v][i]] == false)
        {
            if(dfs(adj_list, adj_list[v][i], visited, v))
            {
                return 1;
            }
        }

        else if(adj_list[v][i] != parent)
        {
            return 1;
        }
    }
    return 0;
}

void isTree(vector<vector<int>> adj_list, int vertices)
{
    vector<bool> visited (vertices, false);

    if(dfs(adj_list, 0, visited, -1))
    {
        cout << -1 << endl;
        return;
    }
    for(int i = 0; i < vertices; i++)
    {
        if(visited[i] == false)
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << 1 << endl;
    return;
}

int main()
{
    int vertices = 5;
    vector<vector<int>> adj_list(vertices);
    vector<bool> visited (vertices, false);
    // addEdge(adj_list, 0, 1);
    // addEdge(adj_list, 0, 3);
    // addEdge(adj_list, 0, 5);

    // addEdge(adj_list, 1, 0);
    // addEdge(adj_list, 1, 2);
    // addEdge(adj_list, 1, 5);

    // addEdge(adj_list, 2, 1);
    // addEdge(adj_list, 2, 3);
    // addEdge(adj_list, 2, 4);

    // addEdge(adj_list, 3, 0);
    // addEdge(adj_list, 3, 2);

    // addEdge(adj_list, 4, 2);

    // addEdge(adj_list, 5, 0);
    // addEdge(adj_list, 5, 1);

    addEdge(adj_list, 1, 0);
    addEdge(adj_list, 0, 1);
    addEdge(adj_list, 0, 2);
    addEdge(adj_list, 0, 3);
    addEdge(adj_list, 3, 4);

    cout << "To check if the tree is a graph is a tree or not" << endl;
    isTree(adj_list, vertices);
    
    return 0;
}