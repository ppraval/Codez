#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "leetcode";
    string t = s;
    reverse(t.begin(), t.end());
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << n - dp[n][n];
    return 0;
}