#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    vector<vector<int>> graph = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0;
    int dst = 3;
    int k = 1;
    
    vector<pair<int, int>> adj[n];

    for(auto i : graph)
    {
        adj[i[0]].push_back({i[1], i[2]});
    }

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});

    vector<int> distance(n, INT_MAX);
    distance[src] = 0;

    while(!q.empty())
    {
        auto x = q.front();
        q.pop();
        int stops = x.first;
        int curr_node = x.second.first;
        int cost = x.second.second;

        if(stops > k)
            break;
        for(auto i : adj[curr_node])
        {
            int adj_node = i.first;
            int weight = i.second;

            if(cost + weight < distance[adj_node])
            {
                distance[adj_node] = cost + weight;
                q.push({stops + 1, {adj_node, cost + weight}});
            }
        }
    }
    if(distance[dst] == INT_MAX)
    {
        cout << -1;
        return -1;
    }
    cout << distance[dst]; 
    return distance[dst];
}