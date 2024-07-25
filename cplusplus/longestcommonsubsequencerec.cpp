#include<bits/stdc++.h>
using namespace std;

int rec(string s, string t, int i, int j, vector<vector<int>> &dp)
{
    if(i < 0 || j < 0)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(s[i] == t[j])
        return dp[i][j] = 1 + rec(s, t, i - 1, j - 1, dp);
    return dp[i][j] = max(rec(s, t, i, j - 1, dp), rec(s, t, i - 1, j, dp));
}

int main()
{
    string s = "adebc";
    string t = "dcadbm";
    vector<vector<int>> dp(s.length(), vector<int> (t.length(), -1));
    cout << rec(s, t, s.length() - 1, t.length() - 1, dp) << endl;
    for(auto x : dp)
    {
        for(int i : x)
        {
            i = 0;
        }
    }
    cout << s << " == " << t << endl;
    vector<vector<int>> dp1(s.length() + 1, vector<int> (t.length() + 1, 0));
    for(int i = 1; i <= s.length(); i++)
    {
        for(int j = 1; j <= t.length(); j++)
        {
            cout << s[i] << "~" << t[j] << endl;
            if(s[i - 1] == t[j - 1])
                dp1[i][j] = 1 + dp1[i - 1][j - 1];
            else
                dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]);
        }
        for(auto x : dp1)
        {
            for(int i : x)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        cout << "---------------" << endl;
    }
    cout << dp1[s.length()][t.length()];
    return 0;
}