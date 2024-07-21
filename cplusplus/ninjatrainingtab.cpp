#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3;
    vector<vector<int>> m = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };
    vector<vector<int>> dp (n, vector<int> (4, 0));
    dp[0][0] = max(m[0][1], m[0][2]);
    dp[0][1] = max(m[0][0], m[0][2]);
    dp[0][2] = max(m[0][1], m[0][0]);
    dp[0][3] = max({m[0][1], m[0][0], m[0][2]});

    for(auto x : dp){
        for(int i : x)
            cout << i << " ";
        cout << endl;}

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            dp[i][j] = 0;
            for(int k = 0; k <= 2; k++)
            {
                if(k != j)
                {
                    int act = m[i][k] + dp[i - 1][k];
                    dp[i][j] = max(dp[i][j], act);
                }
            }
        }
    }
    cout << dp[n - 1][3];
    return 0;
}