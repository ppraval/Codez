#include<bits/stdc++.h>
using namespace std;

int rec(int i, int j, vector<vector<int>> g, vector<vector<int>> &dp)
{
    if(i == 0 && j == 0)
        return g[i][j];
    if(i < 0 || j < 0)
        return INT_MAX;
    if(dp[i][j] != -1)
        return dp[i][j];
    int up = INT_MAX;
    int left = INT_MAX;
    if(i > 0)
        up = g[i][j] + rec(i - 1, j, g, dp);
    if(j > 0)
        left = g[i][j] + rec(i, j - 1, g, dp);
    return dp[i][j] = min(up, left);
}


int main()
{
    vector<vector<int>> g = {{1,3,1}, {1,5,1}, {4,2,1}};
    vector<vector<int>> dp (g.size(), vector<int> (g[0].size(), -1));
    rec(g.size() - 1, g.size() - 1, g, dp);
    for(auto x : dp)
    {
        for(int i : x)
        {
            cout << i <<  " ";
        }
        cout << endl;
    }
    cout << dp[g.size() - 1][g.size() - 1];
    return 0;
}