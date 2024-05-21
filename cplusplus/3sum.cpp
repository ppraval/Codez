#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans;
    set<vector<int>> s;
    
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++)
    {
        int l = i + 1;
        int r = nums.size() - 1;
        while(l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];  
            if(sum == 0)
            {
                s.insert({nums[i], nums[l], nums[r]});
                l++;
                r--;
            }
            else if(sum < 0)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    for(auto &v : s)
        ans.push_back(v);
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