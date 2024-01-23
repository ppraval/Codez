#include<bits/stdc++.h>
using namespace std;


void subset(vector<int> nums, vector<int> set, vector<vector<int>>& ans, int index)
{
    if(index >= nums.size())
    {
        ans.push_back(set);
        return;
    }

    subset(nums, set, ans, index + 1);
    int element = nums[index];
    set.push_back(element);
    // cout << "( ";
    // for(int i = 0; i < set.size(); i++)
    // {
    //     cout << set[i] << " ";
    // }
    // cout << ") " << endl;
    subset(nums, set, ans, index + 1);
}


int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> set;
    subset(nums, set, ans, 0);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << "( ";
        for(int j = 0; j  < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << ") ";
    }
    return 0;
}