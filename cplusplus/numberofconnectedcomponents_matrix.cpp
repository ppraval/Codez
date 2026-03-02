#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& adj_matrix, int u, int v, int n)
{
    adj_matrix[u - 1][v - 1] = 1;
    adj_matrix[v - 1][u - 1] = 1; // since undirected
}

void dfs(vector<vector<int>> adj_matrix, int v, vector<bool>& visited, int n)
{
    visited[v] = true;
    for(int i = 0; i < n; i++)
    {
        if(adj_matrix[v][i] == 1 && visited[i] == false)
            dfs(adj_matrix, i, visited, n);
    }
}

int numberOfConnectedComponents(int n, vector<vector<int>> adj_matrix)
{
    vector<bool> visited (n, false);
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == false)
        {
            dfs(adj_matrix, i, visited, n);
            count++;
        }
    }
    return count;
}

int main()
{
    int vertices = 8;
    vector<vector<int>> adj_matrix(vertices, vector<int>(vertices, 0));
    // addEdge(adj_matrix, 1, 2, vertices);
    // addEdge(adj_matrix, 2, 1, vertices);
    // addEdge(adj_matrix, 3, 4, vertices);
    // addEdge(adj_matrix, 4, 3, vertices);
    // addEdge(adj_matrix, 4, 5, vertices);
    // addEdge(adj_matrix, 5, 4, vertices);

    addEdge(adj_matrix, 1, 2, vertices);
    addEdge(adj_matrix, 2, 1, vertices);
    addEdge(adj_matrix, 2, 3, vertices);
    addEdge(adj_matrix, 3, 2, vertices);
    addEdge(adj_matrix, 3, 4, vertices);
    addEdge(adj_matrix, 4, 3, vertices);
    addEdge(adj_matrix, 4, 5, vertices);
    addEdge(adj_matrix, 4, 6, vertices);
    addEdge(adj_matrix, 5, 4, vertices);
    addEdge(adj_matrix, 6, 4, vertices);
    addEdge(adj_matrix, 6, 7, vertices);
    addEdge(adj_matrix, 7, 6, vertices);
    addEdge(adj_matrix, 7, 8, vertices);


    int n = numberOfConnectedComponents(vertices, adj_matrix);
    cout << "answer = " << n << endl;
    return 0;
}