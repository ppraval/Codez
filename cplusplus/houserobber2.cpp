#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> nums)
{
    vector<int> dp(nums.size(), -1);
    dp[0] = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        int pick = nums[i];
        if(i > 1)
            pick += dp[i - 2];
        int no_pick = 0 + dp[i - 1];
        dp[i] = max(pick, no_pick);
    }
    return dp[nums.size() - 1];
}

int main()
{
    vector<int> nums = {1,5,1,2,6};
    int n = nums.size();
    vector<int> arr1, arr2;
    for(int i = 0; i < nums.size(); i++)
    {
        if(i != 0)
            arr1.push_back(nums[i]);
        if(i != nums.size() - 1)
            arr2.push_back(nums[i]);
    }
    cout << max(solve(arr1), solve(arr2));
    return 0;
}