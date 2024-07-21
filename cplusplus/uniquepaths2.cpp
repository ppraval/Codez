#include<bits/stdc++.h>
using namespace std;

int rec(int i, int j, vector<vector<int>> m, vector<vector<int>> &dp)
{
    if(i > 0 && j > 0 && m[i][j] == -1)
    {
        return 0;
    }
    if(i == 0 && j == 0)
        return 1;
    if(i < 0 || j < 0)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int up = rec(i - 1, j, m, dp);
    int down = rec(i, j - 1, m, dp);
    return dp[i][j] = up + down;
}

int main()
{
    vector<vector<int>> maze{
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };
    int n = maze.size();
    int m = maze[0].size();
    vector<vector<int>> dp(n, vector<int> (m, -1));
    cout << rec(n - 1, m - 1, maze, dp);
    for(auto x : dp)
        for(int i : x)
            i = -1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i > 0 && j > 0 && maze[i][j] == -1)
            {
                dp[i][j] = 0;
                continue;
            }
            if(i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            int up = 0;
            int left = 0;
            if(i > 0)
                up += dp[i - 1][j];
            if(j > 0)
                left += dp[i][j - 1];
            dp[i][j] = up + left;
        }
    }
    cout << endl << dp[n - 1][m - 1];
    return 0;
}