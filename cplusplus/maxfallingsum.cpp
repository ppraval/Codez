#include<bits/stdc++.h>
using namespace std;

int rec(int i, int j, int k, vector<vector<int>> m, vector<vector<int>> &dp)
{
    if(j < 0 || j >= k)
    {
        return INT_MIN;
    }
    if(i == 0)
    {
        return m[0][j];
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int up = m[i][j] + rec(i - 1, j, k, m, dp);
    int left = m[i][j] + rec(i - 1, j - 1, k, m, dp);
    int right = m[i][j] + rec(i - 1, j + 1, k, m, dp);
     
    return dp[i][j] = max(up, max(left, right));
}


int main()
{
    vector<vector<int>> m = {
        {1, 2, 10, 4},
        {100, 3, 2, 1},
        {1, 1, 20, 2},
        {1, 2, 2, 1}
    };
    int n = m.size();
    int k = m[0].size();
    vector<vector<int>> dp(n, vector<int> (k, -1));
    int max_val = INT_MIN;
    for(int i = 0; i < k; i++)
    {
        int ans = rec(n - 1, i, k, m, dp);
        max_val = max(max_val, ans);
    }
    cout << max_val << endl;
    return 0;
}