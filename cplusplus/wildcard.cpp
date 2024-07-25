#include<bits/stdc++.h>
using namespace std;

bool rec(string s, string t, int i, int j, vector<vector<int>> &dp)
{
    if(i < 0 && j < 0)
        return 1;
    if(i < 0 && j >= 0)
        return 0;
    if(i >= 0 && j < 0)
    {
        for(int k = 0; k <= i; k++)
        {
            if(t[i] != '*')
                return false;
        }
        return true;
    }
    
    if(dp[i][j] != false)
        return dp[i][j];
    if(t[i] == '?' || s[i] == t[j])
        return dp[i][j] = rec(s, t, i - 1, j - 1, dp);    
    
    if(t[i] == '*')
        return dp[i][j] = rec(s, t, i - 1, j, dp) || rec(s, t, i, j - 1, dp);
    return false;
}

int main()
{
    string t = "?ay";
    string s = "ray";
    vector<vector<int>> dp(s.size(), vector<int> (t.size(), -1));
    cout << rec(s, t, s.size() - 1, t.size() - 1, dp);
    return 0;
}