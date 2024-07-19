#include<bits/stdc++.h>
using namespace std;

int rec(int i, vector<int> h, vector<int> dp)
{
    if(i == 0)
        return 0;
    if(dp[i] != -1)
        return dp[i];
    int jump2 = INT_MAX;
    int jump1 = rec(i-1, h, dp) + abs(h[i] - h[i - 1]);
    if(i > 1)
        jump2 = rec(i-2, h, dp) + abs(h[i] - h[i - 2]);
    return dp[i] = min(jump1, jump2);
}

int main()
{
    vector<int> h = {30,10,60,10,60,50};
    int n = h.size();
    vector<int> dp(n, -1);
    cout << rec(n - 1, h, dp) << endl;
    for(int i : dp)
        i = -1;
    dp[0] = 0;
    for(int i : dp)cout << i << " ";
    cout << endl;
    for(int i = 1; i < n; i++)
    {
        int jump2 = INT_MAX;
        int jump1 = dp[i - 1] + abs(h[i] + h[i - 1]);
        if(i > 1)
            jump2 = dp[i - 2] + abs(h[i] - h[i - 2]);
        dp[i] = min(jump1, jump2);
    }
    cout << dp[n - 1];
    return 0;
}