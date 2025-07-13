#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) 
    {
        int n = arr.size();
        if (n <= 1) return 0;

        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < n; ++i) 
        {
            graph[arr[i]].push_back(i);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int steps = 0;

        while (!q.empty()) 
        {
            int sz = q.size();
            while (sz--) 
            {
                int idx = q.front(); q.pop();
                if (idx == n - 1) return steps;

                if (idx - 1 >= 0 && !visited[idx - 1]) 
                {
                    visited[idx - 1] = true;
                    q.push(idx - 1);
                }

                if (idx + 1 < n && !visited[idx + 1]) 
                {
                    visited[idx + 1] = true;
                    q.push(idx + 1);
                }
                for (int neighbor : graph[arr[idx]]) 
                {
                    if (!visited[neighbor]) 
                    {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }

                graph[arr[idx]].clear();
            }
            steps++;
        }
        return -1; 
    }
};

int main() 
{
    Solution sol;
    vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    cout << sol.minJumps(arr) << endl; // Output: 3
    return 0;
}