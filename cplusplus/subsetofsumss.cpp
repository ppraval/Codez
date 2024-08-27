#include<bits/stdc++.h>
using namespace std;

int rec(int i, int tar, vector<int> arr, vector<vector<int>> &dp)
{
    if(tar == 0)
    {
        return 1;
    }
    if(i == 0)
    {
        return arr[0] == tar;
    }
    if(dp[i][tar] != -1)
    {
        return dp[i][tar];
    }
    bool no_take = rec(i - 1, tar, arr, dp);
    bool take = 0;
    if(arr[i] <= tar)
        take = rec(i - 1, tar - arr[i], arr, dp);
    return dp[i][tar] = take or no_take;
}

int main()
{
    int tar = 4;
    vector<int> arr = {1,2,3,4};
    vector<vector<int>> dp(arr.size(), vector<int> (tar + 1, -1));
    int n = arr.size();
    cout << rec(n - 1, tar, arr, dp);
    return 0;
}