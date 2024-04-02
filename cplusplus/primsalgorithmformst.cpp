#include<bits/stdc++.h>
using namespace std;

void printMst(vector<int> parent, vector<vector<int>> adj_matrix, int vertices, vector<int> path)
{
    int sum = 0;
    for(int i = 0; i < vertices; i++)
    {
        if(parent[i] == -1)
        {
            continue;
        }
        sum += adj_matrix[i][parent[i]];
    }
    cout << "Edge weight of the mst = " << sum << endl;
    for(int i : path)
    {
        if(parent[i] == -1)
            continue;
        cout << parent[i] << " " << i << " ";
    }
}

int minKey(vector<int> key, vector<bool> curr_mst, int vertices, vector<int>& path)
{
    int min = INT_MAX, min_index;
    // cout << "The min key process" << endl;
    for (int v = 0; v < vertices; v++)
    {
        if(curr_mst[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    path.push_back(min_index);
    // cout << "The min index = " << min_index << endl;
    return min_index;
}

void primsMST(vector<vector<int>> adj_matrix, int vertices, int vertex)
{
    vector<int> parent(vertices);
    vector<int> key(vertices);
    vector<bool> curr_mst(vertices);
    vector<int> path;
    
    for(int i = 0; i < vertices; i++)
    {   
        key[i] = INT_MAX;
        curr_mst[i] = false;
    }
    key[vertex] = 0;
    parent[vertex] = -1;

    for(int count = 0; count < vertices; count++)
    {
        int u = minKey(key, curr_mst, vertices, path);
        curr_mst[u] = true;
        for (int v = 0; v < vertices; v++)
        {
            if(adj_matrix[u][v] && curr_mst[v] == false && adj_matrix[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = adj_matrix[u][v];
            }
        }
    }
    
    // for(int i : parent)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    printMst(parent, adj_matrix, vertices, path);
}

int main()
{
    int vertices = 5;
    // vector<vector<int>> adj_matrix = {
    //     {0, 2, 0, 3, 7, 0},
    //     {2, 0, 1, 0, 8, 0},
    //     {0, 1, 0, 4, 0, 5},
    //     {3, 0, 4, 0, 0, 6},
    //     {7, 8, 0, 0, 0, 0},
    //     {0, 0, 5, 6, 0, 0}
    // };

    vector<vector<int>> adj_matrix = {
        {0, 1, 5, 0, 0},
        {1, 0, 2, 0, 0},
        {5, 2, 0, 3, 6},
        {0, 0, 3, 0, 4},
        {0, 0, 6, 4, 0}
    };

    primsMST(adj_matrix, vertices, 1);
    return 0;
}