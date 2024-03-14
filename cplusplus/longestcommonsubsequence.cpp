#include<bits/stdc++.h>
using namespace std;

int main()
{
    string text1 = "abcde";
    string text2 = "ace";
    vector<vector<int>> dp(text1.length() + 1, vector<int> (text2.length() + 1, 0));
    for(int i = text1.length() - 1; i >= 0; i--)
    {
        for(int j = text2.length() - 1; j >= 0; j--)
        {
            int ans = 0;
            if(text1[i] == text2[j])
            {
                ans = 1;
                if(i < text1.length() - 1 && j < text2.length() - 1)
                    ans += dp[i + 1][j + 1];
            }
            ans = max(ans, dp[i][j + 1]);
            ans = max(ans, dp[i + 1][j]);
            dp[i][j] = ans;
        }
    }
    cout << dp[0][0] << endl;
    return dp[0][0];
}