#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;
        int steps = 0;

        while (!q.empty()) 
        {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front(); q.pop();
                if (steps > 0 && (x == 0 || y == 0 || x == m - 1 || y == n - 1)) 
                {
                    return steps;
                }

                for (auto& d : directions) 
                {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                        maze[nx][ny] == '.' && !visited[nx][ny]) 
                        {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<char>> maze = {
        {'+', '+', '.', '+', '+', '+', '+', '+'},
        {'.', '.', '.', '.', '.', '.', '.', '+'},
        {'+', '+', '+', '+', '+', '+', '+', '.'}
    };
    vector<int> entrance = {1, 2};

    cout << sol.nearestExit(maze, entrance) << endl; // Output: 1
    return 0;
}