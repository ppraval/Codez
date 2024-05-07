#include<bits/stdc++.h>
using namespace std;

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

vector<int> dijsktraShortestPath(int vertices, vector<vector<int>> matrix, int start)
{
    vector<int> distance(vertices, INT_MAX);
    vector<bool> shortestPathSet(vertices, false);

    distance[start] = 0;
    
    for(int count = 0; count < vertices - 1; count++)
    {
        int u = minDistance(vertices, distance, shortestPathSet);
        shortestPathSet[u] = true;
        for(int v = 0; v < vertices; v++)
        {
            if(!shortestPathSet[v] && matrix[u][v] && distance[u] != INT_MAX && distance[u] + matrix[u][v] < distance[v])
            {
                distance[v] = distance[u] + matrix[u][v];
            }
        }
    }
    return distance;
}


int main()
{
    // int n = 6;
    int n = 3;
    // vector<vector<int>> edges = {{0,1,4},{0,2,1},{1,3,2},{1,4,3},{1,5,1},{2,3,1},{3,5,3},{4,5,2}};
    vector<vector<int>> edges = {{2,1,6}};
    vector<vector<int>> matrix (n, vector<int> (n, 0));

    for(int i = 0; i < edges.size(); i++)
    {
        matrix[edges[i][0]][edges[i][1]] = matrix[edges[i][1]][edges[i][0]] =  edges[i][2];
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "pain" << endl;
    
    vector<int> distance_0 = dijsktraShortestPath(n, matrix, 0);
    vector<int> distance_n_1 = dijsktraShortestPath(n, matrix, n - 1);

    for(int i : distance_0)
        cout << i << " ";
    cout << endl;
    
    for(int i : distance_n_1)
        cout << i << " ";
    cout << endl;
    
    vector<bool> ans(edges.size(), false);
    
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        long long weight = edges[i][2];

        if(distance_0[u] + distance_n_1[v] + weight == distance_0[n - 1])
        {
            ans[i] = true;
        }
        if(distance_0[v] + distance_n_1[u] + weight == distance_0[n - 1])
        {
            ans[i] = true;
        }
    }
    for(bool x : ans)
        cout << x << " ";
    return 0;
}