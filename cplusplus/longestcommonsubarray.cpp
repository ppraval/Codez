#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {1,2,8,2,1};
    vector<int> b = {8,2,1,4,7};
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    int max_val = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = m - 1; j >= 0; j--)
        {
            if(a[i] == b[j])
            {
                cout << "We hit this " << a[i] << "~" << b[j] << endl;
                dp[i][j] = dp[i + 1][j + 1] + 1;
                max_val = max(max_val, dp[i][j]);
            }
        }
        for(auto x : dp)
        {
            for(int k : x)
            {
                cout << k << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << max_val;
    return 0;
}