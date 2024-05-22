#include<bits/stdc++.h>
using namespace std;

void subset(vector<int> nums, vector<int> set, vector<vector<int>>& ans, int i, int n)
{
    if(i >= n)
    {
        ans.push_back(set);
        return;
    }
    subset(nums, set, ans, i + 1, n);
    set.push_back(nums[i]);
    subset(nums, set, ans, i + 1, n);
}

int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;
    vector<int> set;
    int n = nums.size();
    subset(nums, set, ans, 0, n);
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
