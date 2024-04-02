#include<bits/stdc++.h>
using namespace std;

void listToMatrix(int vertices, vector<vector<int>> adj_list, vector<vector<int>> weight_list, vector<vector<int>>& adj_matrix)
{
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        {
            adj_matrix[i][j] = 0;
        }
    }

    for(int i = 0; i < vertices; i++)
    {
        for(int j = 1; j < adj_list[i].size(); j++)
        {
            adj_matrix[i][adj_list[i][j] - 1] = weight_list[i][j];
        }
    }

    // cout << "The final list is = " << endl;
    
    // for(int i = 0; i < vertices; i++)
    // {
    //     for(int j = 0; j < vertices; j++)
    //     {
    //         cout << adj_matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}


int minDistance(int vertices, vector<int>& distance, vector<bool>& shortestPathSet)
{
    int min = INT_MAX, min_index;

    for(int v = 0; v < vertices; v++)
    {
        if(shortestPathSet[v] == false && distance[v] <= min)
        {
            min = distance[v], min_index = v;
        }
    }
    return min_index;
}

void dijsktraShortestPaths(int vertices, vector<vector<int>> adj_matrix, int start)
{
    vector<int> distance(vertices);
    vector<bool> shortestPathSet(vertices);

    for(int i = 0; i < vertices; i++)
    {
        distance[i] = INT_MAX;
        shortestPathSet[i] = false;
    }

    distance[start] = 0;

    for(int count = 0; count < vertices - 1; count++)
    {
        int u = minDistance(vertices, distance, shortestPathSet);
        shortestPathSet[u] = true;
        for(int v = 0; v < vertices; v++)
        {
            if(!shortestPathSet[v] && adj_matrix[u][v] && distance[u] != INT_MAX && distance[u] + adj_matrix[u][v] < distance[v])
            {
                distance[v] = distance[u] + adj_matrix[u][v];
            }
        }
    }

    for(int i : distance)
    {
        cout << i << " ";
    }
}

int main()
{
    int vertices = 5;
    vector<vector<int>> adj_list = {
        {1, 2},
        {2, 1, 3, 4, 5},
        {3, 2, 4},
        {4, 2, 3, 5},
        {5, 2, 4}
    };
    vector<vector<int>> weight_list = {
        {1, 5},
        {2, 5, 10, 2, 3},
        {3, 10, 8},
        {4, 2, 8, 5},
        {5, 3, 5}
    };
    int source = 2;

    vector<vector<int>> adj_matrix(vertices, vector<int> (vertices));

    listToMatrix(vertices, adj_list, weight_list, adj_matrix);


    dijsktraShortestPaths(vertices, adj_matrix, source - 1);
    return 0;
}