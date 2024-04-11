#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& adj_matrix, int vertices)
{
    queue<int> q;
    vector<int> in_degree(vertices, 0);
    int visited = 0;
    
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        {
            if(adj_matrix[i][j] == 1)
            {
                in_degree[j]++;
            }
        }
    }

    for(int i = 0; i < vertices; i++)
    {
        if(in_degree[i] == 0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        visited++;
        for(int i = 0; i < vertices; i++)
        {
            if(adj_matrix[current][i] == 1)
            {
                in_degree[i]--;
                if(in_degree[i] == 0)
                    q.push(i);
            }
        }
    }

    if(visited == vertices)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << 1 << endl;
    }
}

int isCyclic(int vertices, vector<vector<int>> list, vector<bool>& visited, int v, int parent)
{
    visited[v] = true;
    for(int i : list[v])
    {
        if(visited[i] == false)
        {
            if(isCyclic(vertices, list, visited, i, v))
            {
                return 1;
            }
        }
        else if(i != parent)
        {
            return 1;
        }
    }
    return 0;
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
        {1, 3}
    };
    if(isCyclic(vertices, graph, visited, 0, -1))
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}