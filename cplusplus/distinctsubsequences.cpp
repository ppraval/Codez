#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int rec(string s, string t, int i, int j, vector<vector<int>> &dp)
{
    if(i < 0)
        return 0;
    if(j < 0)
        return 1;
    if(dp[i][j] != -1)
        return dp[i][j];
    int res = 0;
    if(s[i] == t[j])
    {
        int no_take = rec(s, t, i - 1, j - 1, dp);
        int take = rec(s, t, i - 1, j, dp);
        res = (take + no_take) % mod;
    }
    else
    {
        res = rec(s, t, i - 1, j, dp);
    }
    dp[i][j] = res;
    return res;
}

int main()
{
    string s = "babgbag";
    string t = "bag";
    vector<vector<int>> dp(s.length(), vector<int> (t.length(), -1));
    cout << rec(s, t, s.length() - 1, t.length() - 1, dp);
    return 0;
}