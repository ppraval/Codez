#include<bits/stdc++.h>
using namespace std;

int minKey(vector<int> key, vector<bool> curr_mst, int vertices)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < vertices; v++)
    {
        if(curr_mst[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMst(vector<int> parent, vector<vector<int>> adj_matrix, int vertices)
{
    cout << "Edge \tWeight" << endl;
    for(int i = 1; i < vertices; i++)
    {
        cout << parent[i] << " - " << i << "\t" << adj_matrix[i][parent[i]] << endl;
    }
}

void primsMST(vector<vector<int>> adj_matrix, int vertices)
{
    vector<int> parent(vertices);
    vector<int> key(vertices);
    vector<bool> curr_mst(vertices);
    
    for(int i = 0; i < vertices; i++)
    {
        key[i] = INT_MAX;
        curr_mst[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < vertices - 1; count++)
    {
        int u = minKey(key, curr_mst, vertices);
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
    printMst(parent, adj_matrix, vertices);
}

int main()
{
    int vertices = 6;
    vector<vector<int>> adj_matrix = {
        {0, 2, 0, 3, 7, 0},
        {2, 0, 1, 0, 8, 0},
        {0, 1, 0, 4, 0, 5},
        {3, 0, 4, 0, 0, 6},
        {0, 0, 5, 6, 0, 0},
        {7, 8, 0, 0, 0, 0}
    };

    // vector<vector<int>> adj_matrix = {
    //     { 0, 2, 0, 6, 0 },
    //     { 2, 0, 3, 8, 5 },
    //     { 0, 3, 0, 0, 7 },
    //     { 6, 8, 0, 0, 9 },
    //     { 0, 5, 7, 9, 0 }
    // };
    primsMST(adj_matrix, vertices);
    return 0;
}