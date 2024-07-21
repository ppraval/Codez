#include<bits/stdc++.h>
using namespace std;

int rec(int i, int j, vector<vector<int>> m, vector<vector<int>> &dp)
{
    if(i == 0 && j == 0)
        return m[0][0];
    if(i < 0 || j < 0)
        return INT_MAX;
    if(dp[i][j] != -1)
        return dp[i][j];
    cout << "The matrix val = " << m[i][j] << endl << endl;
    int up = m[i][j] + rec(i - 1, j, m, dp);
    int left = m[i][j] + rec(i, j - 1, m, dp);
    cout << "for the matrix value = " << m[i][j] << " " << "up = " << up << " left = " << left << " pain = " << min(up, left) << endl << endl;
    return dp[i][j] = min(up, left);
}

int main()
{
    vector<vector<int>> m = {
        {5,9,6},
        {11,5,2}
    };
    int n = 2, k = 3;
    vector<vector<int>> dp(n, vector<int> (k, -1));
    cout << rec(n - 1, k - 1, m, dp) << endl;
    for(auto x : dp)
    {
        for(int i : x)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}