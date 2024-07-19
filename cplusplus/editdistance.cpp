#include<bits/stdc++.h>
using namespace std;

int rec(string s, string t, int i, int j, vector<vector<int>> &dp)
{
    if(i < 0)
        return j + 1;
    if(j < 0)
        return i + 1;
    if(s[i] == t[j])
        return dp[i][j] = rec(s, t, i - 1, j - 1, dp);
    return dp[i][j] = min({rec(s, t, i - 1, j, dp), rec(s, t, i, j - 1, dp), rec(s, t, i - 1, j - 1, dp)}) + 1;
}

int main()
{
    string s = "horse";
    string t = "ros";
    vector<vector<int>> dp(s.length(), vector<int> (t.length(), -1));
    cout << rec(s, t, s.length() - 1, t.length() - 1, dp);
    return 0;
}