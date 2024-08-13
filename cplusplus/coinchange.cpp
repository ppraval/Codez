#include<bits/stdc++.h>
using namespace std;


int main()
{
    vector<int> c = {1,2,5};
    int amt = 11;
    vector<int> dp(amt + 1, INT_MAX);
    sort(c.begin(), c.end());
    dp[0] = 0;
    for(int i = 1; i < amt + 1; i++)
    {
        for(int x : c)
        {
            if(i - x < 0)
                break;
            if(dp[i - x] != INT_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[i - x]);
                // dp[i] = 1 + dp[i - x];
            } 
        }
        // for(int i : dp)
        //     cout << i << " ";
        // cout << endl;
    }
    if(dp[amt] == INT_MAX)
        cout << -1;
    else
        cout << dp[amt];
    return 0;
}