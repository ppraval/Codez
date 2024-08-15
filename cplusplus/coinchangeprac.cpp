#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> c = {25,10,5};
    int tar = 30;
    sort(begin(c), end(c));
    vector<int> dp(tar + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < tar + 1; i++)
    {
        for(int x : c)
        {
            dp[i] = min(dp[i], 1 + dp[i - x]);
        }
    }
    for(int i : dp)
        cout << i << " ";
    cout << endl << dp[tar];
    return 0;
}