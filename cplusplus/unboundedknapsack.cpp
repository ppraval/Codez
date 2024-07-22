#include<bits/stdc++.h>
using namespace std;

int rec(int i, int w, vector<int> val, vector<int> wei, vector<vector<int>> &dp)
{
    if(i == 0)
        return (w / wei[0]) * val[0];
    if(dp[i][w] != -1)
        return dp[i][w];
    int not_take = 0 + rec(i - 1, w, val, wei, dp);
    int take = INT_MIN;
    if(wei[i] <= w)
        take = val[i] + rec(i, w - wei[i], val, wei, dp);
    return dp[i][w] = max(take, not_take);
}

int main()
{
    int n = 3;
    int w = 10;
    vector<int> wei = {2,4,6};
    vector<int> val = {5,11,13};
    vector<vector<int>> dp(n, vector<int> (w + 1, -1));
    cout << rec(n - 1, w, val, wei, dp);
    return 0;
}