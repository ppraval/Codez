#include<bits/stdc++.h>
using namespace std;

bool isSpecial(vector<int> nums, int start, int end)
{
    for (int i = start; i <= end; ++i) 
    {
        if ((nums[i] % 2 == 0 && nums[i + 1] % 2 == 0) || (nums[i] % 2 != 0 && nums[i + 1] % 2 != 0)) 
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> nums = {3,4,1,2,6};
    vector<vector<int>> queries = {{0,2},{2,4}};
    vector<bool> ans;
    for(auto& q : queries)
    {
        int start = q[0];
        int end = q[1];
        if(isSpecial(nums, start, end))
        {
            ans.push_back(true);
        }
        else
        {
            ans.push_back(false);
        }
    }
    for(bool x : ans)
        cout << x << " ";
    return 0;
}