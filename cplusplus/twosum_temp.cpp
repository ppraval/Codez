#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,2,3,4,6};
    int tar = 7;
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++)
    {
        int rem = tar - nums[i];
        if(mp.find(rem) != mp.end())
        {
            cout << mp[rem] << " " << i << endl;
            return 0;
        }
        else
        {
            mp[nums[i]] = i;
        }
    }
    return 0;
}