#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,2,3,1};
    unordered_map<int, int> mp;
    for(int i : nums)
    {
        mp[i]++;
    }
    for(auto i : mp)
    {
        if(i.second > 1)
        {
            cout << "true";
            return true;
        }
    }
    cout << "false";
    return false;
}