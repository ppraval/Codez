#include<bits/stdc++.h>
using namespace std;

int minDistance(int vertices, vector<bool> set, vector<int> distance)
{
    int min = INT_MAX;
    int min_index;

    for(int v = 0; v < vertices; v++)
    {
        if(set[v] == false && distance[v] < min)
        {
            min = distance[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijsktra(int vertices, int vertex, vector<vector<int>> graph)
{
    vector<bool> set(vertices, false);
    vector<int> distance(vertices, INT_MAX);

    distance[vertex] = 0;

    for(int count = 0; count < vertices - 1; count++)
    {
        int u = minDistance(vertices, set, distance);
        set[u] = true;
        for(int v = 0; v < vertices; v++)
        {
            if(graph[u][v] && set[v] == false && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v]; 
            }
        }
    }
    for(int i : distance)
        cout << i << " ";
}

int main()
{
    int vertices = 5;
    vector<vector<int>> graph = {
        {0, 5, 0, 0, 0},
        {5, 0, 10, 2, 3},
        {0, 10, 0, 8, 0},
        {0, 2, 8, 0, 5},
        {0, 3, 0, 5, 0}
    };
    dijsktra(vertices, 0, graph);
    return 0;
}