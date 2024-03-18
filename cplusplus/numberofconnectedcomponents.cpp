#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& adj_list, int u, int v)
{
    adj_list[u - 1].push_back(v - 1);
}

void dfs(vector<vector<int>> adj_list, int v, vector<bool>& visited)
{
    visited[v] = true;
    for(int i = 0; i < adj_list[v].size(); i++)
    {
        if(visited[adj_list[v][i]] == false)
            dfs(adj_list, adj_list[v][i], visited);
    }
}

int numberOfConnectedComponents(int n, vector<vector<int>> adj_list)
{
    vector<bool> visited (n, false);
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == false)
        {
            dfs(adj_list, i, visited);
            count++;
        }
    }
    return count;
}

int main()
{
    int vertices = 8;
    vector<vector<int>> adj_list(vertices);
    vector<bool> visited (vertices, false);
    // addEdge(adj_list, 1, 2);
    // addEdge(adj_list, 2, 1);
    // addEdge(adj_list, 3, 4);
    // addEdge(adj_list, 4, 3);
    // addEdge(adj_list, 4, 5);
    // addEdge(adj_list, 5, 4);

    addEdge(adj_list, 1, 2);
    addEdge(adj_list, 2, 1);
    addEdge(adj_list, 2, 3);
    addEdge(adj_list, 3, 2);
    addEdge(adj_list, 3, 4);
    addEdge(adj_list, 4, 3);
    addEdge(adj_list, 4, 5);
    addEdge(adj_list, 4, 6);
    addEdge(adj_list, 5, 4);
    addEdge(adj_list, 6, 4);
    addEdge(adj_list, 6, 7);
    addEdge(adj_list, 7, 6);
    addEdge(adj_list, 7, 8);


    int n = numberOfConnectedComponents(vertices, adj_list);
    cout << n << endl;
    return 0;
}