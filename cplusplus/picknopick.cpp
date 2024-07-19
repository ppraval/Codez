#include<bits/stdc++.h>
using namespace std;

int rec(vector<int> nums, int i, vector<int> &dp)
{
    if(i < 0)
    {
        return 0;
    }
    if(i == 0)
        return nums[i];
    if(dp[i] != -1)
        return dp[i];
    int pick = nums[i] + rec(nums, i - 2, dp);
    int no_pick = 0 + rec(nums, i - 1, dp);
    return dp[i] = max(pick, no_pick);
}

int main()
{
    vector<int> nums = {2, 1, 4, 9};
    vector<int> dp(nums.size(), -1);
    cout << rec(nums, nums.size() - 1, dp) << endl;

    for(int i : dp)
        i = -1;
    dp[0] = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        int pick = nums[i];
        if(i > 1)
        {
            pick += dp[i - 2];
        }
        int non_pick = dp[i - 1];
        dp[i] = max(pick, non_pick);
    }
    cout << dp[nums.size() - 1];
    return 0;
}