#include<bits/stdc++.h>
using namespace std;

void dfs(int v, int start, vector<bool>& visited, vector<int>& time, vector<vector<int>> adj, int parent, int& min_val)
{
    visited[v] = true;
    time[v] = start; 
    for(int i : adj[v])
    {
        if(visited[i] == false)
        {
            dfs(i, start + 1, visited, time, adj, v, min_val);
        }
        else if(visited[i] &&  i != parent)
        {
            min_val = min(min_val, abs(time[i] - time[v]) + 1);
        }
    }
}

int main()
{
    int n = 7;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0},{3,4},{4,5},{5,6},{6,3}};
    int min_val = INT_MAX;
    vector<vector<int>> adj(n);
    for(int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i = 0; i < n; i++)
    {
        vector<bool> visited(n, false);
        vector<int> time(n, INT_MAX);
        dfs(i, 1, visited, time, adj, -1, min_val);
    }
    if(min_val == INT_MAX)
    {
        cout << -1;
        return -1;
    }
    cout << min_val;
    return 0;
}