#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<vector<int>>& adj_list, int u, int v)
{
    adj_list[u].push_back(v);
}

void bfs(vector<vector<int>>& adj_list, int start, vector<bool>& visited)
{
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";
        
        for(int neighbour : adj_list[current])
        {
            if(visited[neighbour] == false)
            {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
}

int main()
{
    int vertices = 5;
    vector<vector<int>> adj_list(vertices);
    addEdge(adj_list, 0, 1);
    addEdge(adj_list, 0, 2);
    addEdge(adj_list, 1, 3);
    addEdge(adj_list, 1, 4);
    addEdge(adj_list, 2, 4);

    vector<bool> visited(vertices, false);

    cout << "Breadth First Traversal starting from vertex "
            "0: ";
    bfs(adj_list, 0, visited);

    return 0;
}