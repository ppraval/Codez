#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> nums = {{2,1,3}, {6,5,4}, {7,8,9}};
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 1; j < n + 1; j++)
        {
            if(j < n && j > 1)
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1])) + nums[i - 1][j - 1];
            }
            else if(j == 1)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + nums[i - 1][j - 1];
            }
            else if(j == n)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + nums[i - 1][j - 1];
            }
        }
    }
    // cout << "Pain" << endl;
    int mini = INT_MAX;
        for(int i = 1; i <= n; i++) 
            mini = min(mini, dp[n][i]);
    cout << mini;
    return 0;
}