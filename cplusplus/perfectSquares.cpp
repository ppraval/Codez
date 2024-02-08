#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 12;
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i],  dp[i - j * j] + 1);
        }
    }
    cout << dp[n];
    return 0;
}