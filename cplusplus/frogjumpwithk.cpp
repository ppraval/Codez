#include<bits/stdc++.h>
using namespace std;

int rec(vector<int> h, int i, int k, vector<int> &dp)
{
    if(i == 0)
        return 0;
    if(dp[i] != -1)
        return dp[i];
    int min_val = INT_MAX;
    for(int j = 1; j <= k; j++)
    {
        if(i - j >= 0)
        {
            int jump = rec(h, i - j, k, dp) + abs(h[i] - h[i - j]);
            min_val = min(min_val, jump);
        }
    }
    return dp[i] = min_val;
}

int main()
{
    vector<int> h = {30,10,60,10,60,50};
    int k = 2;
    vector<int> dp(h.size(), -1);
    cout << rec(h, h.size() - 1, k, dp);
    return 0;
}