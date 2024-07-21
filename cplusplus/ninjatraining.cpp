#include<bits/stdc++.h>
using namespace std;

int rec(int i, int j, vector<vector<int>> m, vector<vector<int>> &dp)
{
    if(dp[i][j] != -1)
        return dp[i][j];
    if(i == 0)
    {
        int max_i = 0;
        for(int k = 0; k <= 2; k++)
        {
            if(k != j)
                max_i = max(max_i, m[0][k]);
        }
        return dp[i][j] = max_i;
    }
    int max_i = 0;
    for(int k = 0; k <= 2; k++)
    {
        if(k != j)
        {
            int work = m[i][k] + rec(i - 1, k, m, dp);
            max_i = max(max_i, work);
        }
    }
    return dp[i][j] = max_i;
}

int main()
{
    int n = 3;
    vector<vector<int>> m = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };
    vector<vector<int>> dp(n, vector<int> (4,-1));
    cout << rec(n - 1, 3, m, dp);
    return 0;
}