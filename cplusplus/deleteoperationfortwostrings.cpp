#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "sea";
    string t = "eat";
    int n = s.length();
    int m = t.length();
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
    cout << m + n - 2 * dp[n][m];
    return 0;
}