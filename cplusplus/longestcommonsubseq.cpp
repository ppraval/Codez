#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcde";
    string t = "ace";
    vector<vector<int>> dp(s.length() + 1, vector<int> (t.length() + 1, 0));
    for(int i = 1; i <= s.length(); i++)
    {
        // cout << "pain" << endl;
        for(int j = 1; j <= t.length(); j++)
        {
            if(s[i] == t[j])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            else
            {
                dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }
    cout << dp[s.length()][t.length()];
    return 0;
}