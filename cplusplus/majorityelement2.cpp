#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {3,2,3};
    unordered_map<int, int> mp;
    int n = nums.size();
    for(int i : nums)
        mp[i]++;
    vector<int> ans;
    for(auto x : mp)
    {
        if(x.second > (n / 3))
        {
            ans.push_back(x.second);
        }
    }
    for(int i : ans)
        cout << i << " ";
    return 0;
}