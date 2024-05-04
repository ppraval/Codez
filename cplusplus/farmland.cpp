#include<bits/stdc++.h>
using namespace std;

void dfs(int v, int vertices, vector<bool> visited, vector<vector<int>> graph)
{
    visited[v] = true;
    for(int u = 0; u < vertices; u++)
    {
        if(graph[v][u] == 1)
        {
            if(visited[u] == false)
            {
                dfs(u, vertices, visited, graph);
            }
        }
    }
}

int main()
{
    vector<vector<int>> graph = {{ 1 , 1 , 1 , 1 , 0 },{ 1 , 1 , 0 , 1 , 0 },{ 1 , 1 , 0 , 0 , 0 },{ 0 , 0 , 0 , 0 , 0 }};
    int n = graph.size();
    vector<bool> visited(n, false);
    int ans = 0;
    for(int v = 0; v < n; v++)
    {
        if(visited[v] == false)
        {
            dfs(v, n, visited, graph);
            ans++;
        }
    }
    cout << ans;
    return 0;
}