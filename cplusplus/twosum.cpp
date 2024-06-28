#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {2,7,11,15};
    int t = 9;
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++)
    {
        int val = abs(nums[i] - t);
        if(mp.find(val) != mp.end())
        {
            cout << nums[i] << " " << val;
            return 0;
        }
        mp[nums[i]] = i;
    }
    return 0;
}