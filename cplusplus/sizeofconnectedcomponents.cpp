#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& adj_list, int u, int v)
{
    adj_list[u - 1].push_back(v - 1);
}

void dfs(vector<vector<int>> adj_list, int v, vector<bool>& visited, int& count)
{
    visited[v] = true;
    for(int i = 0; i < adj_list[v].size(); i++)
    {
        if(visited[adj_list[v][i]] == false)
        {
            count++;
            dfs(adj_list, adj_list[v][i], visited, count);
        }
    }
}

int sizeOfConnectedComponents(int n, vector<vector<int>> adj_list)
{
    vector<bool> visited (n, false);
    vector<int> counts;
    for(int i = 0; i < n; i++)
    {
        int count = 1;
        if(visited[i] == false)
        {
            dfs(adj_list, i, visited, count);
            counts.push_back(count);
        }
    }
    sort(counts.begin(), counts.end());
    for(int c : counts)
        cout << c << " ";
    cout << endl;
    return 0;
}

int main()
{
    int vertices = 8;
    vector<vector<int>> adj_list(vertices);
    vector<bool> visited (vertices, false);
    // addEdge(adj_list, 1, 2);
    // addEdge(adj_list, 2, 1);
    // addEdge(adj_list, 3, 4);
    // addEdge(adj_list, 4, 3);
    // addEdge(adj_list, 4, 5);
    // addEdge(adj_list, 5, 4);

    addEdge(adj_list, 1, 2);
    addEdge(adj_list, 2, 1);
    addEdge(adj_list, 2, 3);
    addEdge(adj_list, 3, 2);
    addEdge(adj_list, 3, 4);
    addEdge(adj_list, 4, 3);
    addEdge(adj_list, 4, 5);
    addEdge(adj_list, 4, 6);
    addEdge(adj_list, 5, 4);
    addEdge(adj_list, 6, 4);
    addEdge(adj_list, 6, 7);
    addEdge(adj_list, 7, 6);
    addEdge(adj_list, 7, 8);

    sizeOfConnectedComponents(vertices, adj_list);
    return 0;
}