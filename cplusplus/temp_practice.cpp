#include<bits/stdc++.h>
using namespace std;

bool rec(int i, int k, vector<int> nums, vector<vector<int>> &dp)
{
    if(k == 0)
    {
        // cout << "Target has been found" << endl;
        return true;
    }
    if(i == 0)
    {
        // cout << "does " << nums[i] << " = " << k << "? ~ " << (nums[i] == k) << endl;
        return nums[0] == k;
    }
    if(dp[i][k] != -1)
        return dp[i][k];
    // cout << "no take starts from ~ " << nums[i] << endl;
    bool no_take = rec(i - 1, k, nums, dp);
    bool take = false;
    if(nums[i] <= k)
    {
        // cout << "take starts from ~ " << nums[i] << endl;
        bool take = rec(i - 1, k - nums[i], nums, dp);
    }
    // cout << nums[i] << "~" << k  << " take = " << take << " no take = " << no_take << "\n";
    return dp[i][k] = no_take or take;
}

int main()
{
    vector<int> nums = {1,2,3,4};
    int k = 4;
    vector<vector<int>> dp(nums.size(), vector<int> (k + 1, -1));
    cout << rec(nums.size() - 1, k, nums, dp) << endl;
    cout << "k = ";
    for(int i = 0; i < k + 1; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for(int i = 0; i < nums.size(); i++)
    {
        cout << i << " ";
        for(int j = 0; j < k + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}