#include<bits/stdc++.h>
using namespace std;

int main()
{
    string t1 = "abcde", t2 = "ace";
    int n = t1.size();
    int m = t2.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = m - 1; j >= 0; j--)
        {
            int ans = 0;
            if(t1[i] == t2[j])
            {
                ans = 1;
                if(i < n - 1 && j < m - 1)
                    ans += dp[i + 1][j + 1];
            }
            ans = max(ans, dp[i][j + 1]);
            ans = max(ans, dp[i + 1][j]);
			dp[i][j] = ans;
        }
		for(auto x : dp)
		{
			for(int a : x)
			{
				cout << a << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
    cout << dp[0][0];
    return 0;
}