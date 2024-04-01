#include<bits/stdc++.h>
using namespace std;

void makeSet(int vertices, vector<int>& parent, vector<int>& rank)
{
    for(int i = 0; i < vertices; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> parent, int component)
{
    if(parent[component] == component)
    {
        return parent[component];
    }
    return parent[component] = findParent(parent, parent[component]);
}

void unionSet(int vertices, int u, int v, vector<int>& parent, vector<int>& rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;  
    }
}

void createEdgeList(int vertices, vector<vector<int>>& edge_list, vector<vector<int>> adj_list, vector<vector<int>> weight_list)
{
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 1; j < adj_list[i].size(); j++)
        {
            // edge_list.push_back({i, adj_list[i][j], weight_list[i][j]});
            edge_list.push_back({weight_list[i][j], adj_list[i][j], i});
        }
    }
}

void printEdgeList(vector<vector<int>> edge_list)
{
    cout << "The edge list is" << endl;
    for(int i = 0; i < edge_list.size(); i++)
    {
        cout << edge_list[i][0] << " " << edge_list[i][1] << " " << edge_list[i][2] << endl;
    }
}

void kruskalMST(int vertices, vector<vector<int>> edge_list)
{
    sort(edge_list.begin(), edge_list.end());
    vector<int> parent(vertices);
    vector<int> rank(vertices);

    makeSet(vertices, parent, rank);

    int min_weight = 0;
    for(int i = 0; i < edge_list.size(); i++)
    {
        int u = findParent(parent, edge_list[i][1]);
        int v = findParent(parent, edge_list[i][2]);
        int weight = edge_list[i][0];

        if(u != v)
        {
            unionSet(vertices, u, v, parent, rank);
            min_weight += weight;
        }
    }

    cout << "The min weight of the MST = " << min_weight << endl;
}

int main()
{
    // int vertices = 5;
    int vertices = 6;
    vector<vector<int>> adj_list(vertices, vector<int> (vertices));
    vector<vector<int>> weight_list(vertices, vector<int> (vertices));
    // adj_list = {
    //     {0, 1, 2, 3, 4},
    //     {1, 0, 2},
    //     {2, 0, 1, 3},
    //     {3, 0, 2, 4},
    //     {4, 0, 3}
    // };
    // weight_list = {
    //     {0, 1, 7, 10, 5},
    //     {1, 1, 3},
    //     {2, 7, 3, 4},
    //     {3, 10, 4, 2},
    //     {4, 5, 2}
    // };

    adj_list = {
        {0, 1, 2},
        {1, 0, 2, 4},
        {2, 0, 1, 3, 4},
        {3, 2, 4, 5},
        {4, 1, 2, 3, 5},
        {5, 3, 4}
    };
    weight_list = {
        {0, 7, 8},
        {1, 7, 3, 6},
        {2, 8, 3, 3, 4},
        {3, 3, 2, 2},
        {4, 6, 4, 2, 5},
        {5, 2, 5}
    };

    vector<vector<int>> edge_list;
    createEdgeList(vertices, edge_list, adj_list, weight_list);
    kruskalMST(vertices, edge_list);
    return 0;
}