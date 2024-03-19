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
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}

int main()
{
    int vertices = 6;
    vector<vector<int>> adj_matix = {{0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 0, 0}};
    bfs(adj_matix, vertices);
    return 0;
}