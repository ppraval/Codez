#include<bits/stdc++.h>
using namespace std;

bool dfs(int vertices, int v, vector<bool>& visited, vector<int>& colour, vector<vector<int>> graph)
{
    visited[v] = true;
    for(int u : graph[v])
    {
        if(visited[u] == false)
        {
            colour[u] != colour[v];
            if(!dfs(vertices, u, visited, colour, graph))
            {
                return false;
            }
        }
        else if(colour[u] == colour[v])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    vector<bool> visited(graph.size(), false);
    vector<int> colour(graph.size());
    colour[0] = 1;
    if(dfs(graph.size(), 0, visited, colour, graph))
    {
        cout << "True";
        return 1;
    }
    cout << "False";
    return 0;
}