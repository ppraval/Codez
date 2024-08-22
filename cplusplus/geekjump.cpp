#include<bits/stdc++.h>
using namespace std;

int rec(vector<int> h, int i, vector<int>& dp)
{
    if(i == 0)
        return 0;
    if(dp[i] != -1)
        return dp[i];
    int jump1 = rec(h, i - 1, dp) + abs(h[i] - h[i - 1]);
    int jump2 = INT_MAX;
    if(i > 1)
        jump2 = rec(h, i - 2, dp) + abs(h[i] - h[i - 2]);
    return dp[i] = min(jump1, jump2);
}

int main()
{
    vector<int> h = {10, 20, 30, 10};
    vector<int> dp(h.size(), -1);
    int n = h.size();
    cout << rec(h, n - 1, dp);
    return 0;
}