#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "bbabcbcab";
    string t = s;
    reverse(t.begin(), t.end());
    int n = t.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][m];
    return 0;
}