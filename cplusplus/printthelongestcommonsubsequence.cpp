#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcde";
    string t = "bdgek";
    vector<vector<int>> dp(s.size() + 1, vector<int> (t.size() + 1, 0));
    for(int i = 1; i <= s.length(); i++)
    {
        for(int j = 1; j <= t.length(); j++)
        {
            if(s[i] == t[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int len = dp[s.length()][t.length()];
    int i = s.length();
    int j = t.length();
    int idx = len - 1;
    string ans = "";
    for(int k = 0; k < len; k++)
        ans += '\0';
    while(i > 0 && j > 0)
    {
        if(s[i - 1] == t[j - 1])
        {
            ans[idx] = s[i - 1];
            idx--, i--, j--;
        }
        else if(s[i - 1] > t[j - 1])
            i--;
        else
            j--;
    }
    cout << ans << endl;
    return 0;
}