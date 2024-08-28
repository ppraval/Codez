#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "bbabcbcab";
    string t = s;
    reverse(begin(t), end(t));
    int n = s.length();
    int m = n;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = n;
    int j = i;
    string ans = "";
    while(i > 0 && j > 0)
    {
        if(s[i - 1] == t[j  - 1])
        {
            ans += s[i - 1];
            i--, j--;
        }
        else if(s[i - 1] > t[j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout << ans; 
    return 0;
}