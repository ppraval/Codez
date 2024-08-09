#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {0,5,3,2,4,1};
    unordered_map<int, int> mp;
    vector<int> ans;
    for(int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]] = i;
    }
    for(int i = 0; i < nums.size(); i++)
    {
        ans.push_back(mp[i]);
    }
    for(int i : ans)
        cout << i << " ";
    return 0;
}