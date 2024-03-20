#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& adj_list, int u, int v)
{
    adj_list[u].push_back(v);
}

void dfs(int v, vector<vector<int>>& adj_list, vector<bool>& visited, vector<int>& disc, vector<int>& low, int parent, int& time, int& count)
{
    visited[v] = true;
    disc[v] = low[v] = ++time;

    for(int i = 0; i < adj_list[v].size(); i++)
    {
        int u = adj_list[v][i];

        if(u == parent)
        {
            continue;
        }
        if(visited[u])
        {
            low[v] = min(low[v], disc[u]);
        }
        else
        {
            parent = v;
            dfs(u, adj_list, visited, disc, low, parent, time, count);
            low[v] = min(low[v], low[u]);
        }
        if(low[u] > disc[v])
        {
            count++;
        }         
    }
}

void noOfBridges(vector<vector<int>> adj_list, int vertices)
{
    vector<bool> visited(vertices, false);
    vector<int> disc (vertices, -1);
    vector<int> low (vertices, -1);
    int parent = -1;
    int time = 0;
    int count = 0;

    for(int i = 0; i < vertices; i++)
    {
        if(visited[i] == false)
        {
            dfs(i, adj_list, visited, disc, low, parent, time, count);
        }
    }
    cout << count << endl;
}

int main()
{
    int vertices = 5;
    vector<vector<int>> adj_list(vertices);
    addEdge(adj_list, 0, 2);
    addEdge(adj_list, 0, 3);
    addEdge(adj_list, 1, 0);
    addEdge(adj_list, 2, 1);
    addEdge(adj_list, 3, 4);

    noOfBridges(adj_list, vertices);
    return 0;
}