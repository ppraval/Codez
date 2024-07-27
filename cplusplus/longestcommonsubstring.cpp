#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcjklp";
    string t = "acjkp";
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    int max_val = INT_MIN;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                max_val = max(max_val, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    cout << max_val << endl;
    return 0;
}