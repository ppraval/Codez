#include<bits/stdc++.h>
using namespace std;

bool rec(int i, int tar, vector<int> arr, vector<vector<int>> &dp)
{
    if(tar == 0)
        return 1;
    if(i == 0)
        return arr[0] == tar;
    if(dp[i][tar] != -1)
        return dp[i][tar];
    bool notTaken = rec(i - 1, tar, arr, dp);
    bool Taken = 0;
    if(arr[i] <= tar)
        Taken = rec(i - 1, tar - arr[i], arr, dp);
    return dp[i][tar] = notTaken or Taken;
}

int main()
{
    int tar = 4;
    vector<int> arr = {1,2,3,4};
    vector<vector<int>> dp(arr.size(), vector<int> (tar + 1, -1));   
    cout << rec(arr.size() - 1, tar, arr, dp);
    return 0;
}