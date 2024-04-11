#include<bits/stdc++.h>
using namespace std;

void dfs(int vertex, vector<bool>& visited, vector<vector<int>> graph)
{
    visited[vertex] = true;
    cout << vertex << " ";
    for(int v : graph[vertex])
    {
        if(visited[v] == false)
        {
            visited[v] = true;
            // cout << v << " ";
            dfs(v, visited, graph);
        }
    }
}

void bfs(int vertex, vector<bool>& visited, vector<vector<int>> graph)
{
    queue<int> q;
    visited[vertex] = true;
    q.push(vertex);
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        cout << top << " ";
        for(int v : graph[top])
        {
            if(visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }

}

int main()
{
    int vertices =  5;
    vector<bool> visited(vertices, false);
    vector<vector<int>> graph = {
        {1},
        {0, 2, 4},
        {1, 3},
        {2},
        {1}
    };
    dfs(0, visited, graph);
    cout << endl;
    for(auto i : visited)
    {
        i = false;
    }
    bfs(0, visited, graph);
    return 0;
}