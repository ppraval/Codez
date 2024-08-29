    #include<bits/stdc++.h>
    using namespace std;

    int main()
    {
        string s = "geethameenakshi";
        string t = s;
        reverse(begin(t), end(t));
        cout << s << endl;
        cout << t << endl;
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
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
        cout << dp[n][n] << endl;
        int i = n; int j = n;
        string ans = "";
        while(i > 0 && j > 0)
        {
            cout << s[i - 1] << " " << t[j - 1] << endl;
            if(s[i - 1] == t[j - 1])
            {
                ans += s[i - 1];
                i--, j--;
            }
            else if(dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
        reverse(begin(ans), end(ans));
        cout << ans;
        return 0;
    }