#include<bits/stdc++.h>
using namespace std;

void rec(vector<int> nums, int i, vector<vector<int>>& ans, vector<int> temp)
{
    if(i >= nums.size())
    {
        ans.push_back(temp);
        return;
    }
    rec(nums, i + 1, ans, temp);
    temp.push_back(nums[i]);
    rec(nums, i + 1, ans, temp);
    // temp.pop_back();
}

int main()
{
    vector<int> nums = {1,2,3,4,5};
    vector<vector<int>> ans;
    vector<int> temp;
    rec(nums, 0, ans, temp);
    for(auto x : ans)
    {
        for(int i : x)
        {
            cout << i << " "; 
        }
        cout << endl;
    }
    return 0;
}