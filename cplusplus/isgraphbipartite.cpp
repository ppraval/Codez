#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> adj_list, int start, vector<bool> visited)
{
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";
        for(int i : adj_list[current])
        {
            if(visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    vector<bool> visited(graph.size(), false);
    bfs(graph, 0, visited);
    return 0;
}