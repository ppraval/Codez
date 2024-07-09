#include<bits/stdc++.h>
using namespace std;

// void subset(vector<int> nums, vector<int> temp, int index, set<vector<int>> &s)
// {
//     if(index >= nums.size())
//     {
//         sort(temp.begin(), temp.end());
//         s.insert(temp);
//         return;
//     }
//     subset(nums, temp, index + 1, s);
//     int element = nums[index];
//     temp.push_back(element);
//     subset(nums, temp, index + 1, s);
// }  

// int main()
// {
//     vector<int> nums = {1,2,2};
//     vector<int> temp;
//     set<vector<int>> s;
//     vector<vector<int>> ans;
//     subset(nums, temp, 0, s);
//     for(auto x : s)
//         ans.push_back(x);
//     return 0;
// }

void findSubsets(int ind, vector<int> & nums, vector<int> &temp, vector <vector<int>> & ans) 
{
    ans.push_back(temp);
    for (int i = ind; i < nums.size(); i++) 
    {
        if (i != ind && nums[i] == nums[i - 1]) 
            continue;
        temp.push_back(nums[i]);
        findSubsets(i + 1, nums, temp, ans);
        temp.pop_back();
    }
}

int main()
{
    vector<int> nums = {1,2,2};
    vector <vector<int>> ans;
    vector <int> temp;
    sort(nums.begin(), nums.end());
    findSubsets(0, nums, temp, ans);
    return 0;
}