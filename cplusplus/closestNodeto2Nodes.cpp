#include<bits/stdc++.h>
using namespace std;

int findClosestMeetingNode(vector<int>& edges, int node1, int node2) 
{
    int n = edges.size();
    
    auto getDistances = [&](int start) 
    {
        vector<int> dist(n, -1);
        int current = start, d = 0;
        while (current != -1 && dist[current] == -1) 
        {
            dist[current] = d++;
            current = edges[current];
        }
        return dist;
    };
    
    vector<int> dist1 = getDistances(node1);
    vector<int> dist2 = getDistances(node2);

    int minDist = INT_MAX, result = -1;
    for (int i = 0; i < n; ++i) 
    {
        if (dist1[i] != -1 && dist2[i] != -1) 
        {
            int maxDist = max(dist1[i], dist2[i]);
            if (maxDist < minDist) 
            {
                minDist = maxDist;
                result = i;
            }
        }
    }
    return result;
}

int main() {
    vector<int> edges = {2, 2, 3, -1};
    int node1 = 0;
    int node2 = 1;
    int closestNode = findClosestMeetingNode(edges, node1, node2);
    cout << "The closest meeting node is: " << closestNode << endl;
    return 0;
}