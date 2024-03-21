#include<bits/stdc++.h>
using namespace std;

void filldfs(vector<vector<int>>& adj_matrix, vector<bool>& visited, int v, stack<int>& s)
{
    visited[v] = true;
    for(int i = 0; i < adj_matrix[v].size(); i++)
    {
        if(adj_matrix[v][i] == 1)
        {
            if(visited[i] == false)
                filldfs(adj_matrix, visited, i, s);
        }
    }
    s.push(v);
}

void dfs(vector<vector<int>>& adj_matrix, vector<bool>& visited, int v)
{
    visited[v] = true;
    // cout << v << " ";
    for(int i = 0; i < adj_matrix[v].size(); i++)
    {
        if(adj_matrix[v][i] == 1)
        {
            if(visited[i] == false)
                dfs(adj_matrix, visited, i);
        }
    }
}

void kosarajunumberofsccs(vector<vector<int>> adj_matrix, int vertices)
{
    stack<int> s;
    vector<bool> visited (vertices, false);
    int count = 0;
    for(int i = 0; i < vertices; i++)
    {
        if(visited[i] == false)
        {
            filldfs(adj_matrix, visited, i, s);
        }
    }

    vector<vector<int>> adj_matrix_transpose (vertices, vector<int> (vertices));
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        {
            adj_matrix_transpose[i][j] = adj_matrix[j][i];
        }
    }

    for(int i = 0; i < vertices; i++)
    {
        visited[i] = false;
    }

    while(!s.empty())
    {
        int num = s.top();
        s.pop();
        if(visited[num] == false)
        {
            dfs(adj_matrix_transpose, visited, num);
            count++;
        }
    }
    cout << count << endl;
    return;
}

int main()
{
    int vertices = 6;
    vector<vector<int>> adj_matrix = {{0, 1, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 1}, {0, 0, 0, 1, 0, 0}};
    kosarajunumberofsccs(adj_matrix, vertices);
    return 0;
}