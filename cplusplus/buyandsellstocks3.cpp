#include<bits/stdc++.h>
using namespace std;

int rec(vector<int> prices, int curr_day, int left, vector<vector<int>> &dp)
{
    if(curr_day == prices.size() or left == 0)
        return 0;
    if(dp[curr_day][left] == -1)
    {
        int ans1 = rec(prices, curr_day + 1, left, dp);
        int ans2;
        if(left % 2)
            ans2 = rec(prices, curr_day + 1, left - 1, dp) + prices[curr_day];
        else
            ans2 = rec(prices, curr_day + 1, left - 1, dp) - prices[curr_day];
        dp[curr_day][left] = max(ans1, ans2);
    }
    return dp[curr_day][left];
}

int main()
{
    vector<int> prices = {3,3,5,0,0,3,1,4};
    int k = 2;
    int n = k * 2 + 1;
    vector<vector<int>> dp(prices.size(), vector<int> (n, -1));
    cout << rec(prices, 0, 4, dp);
    
    return 0;
}