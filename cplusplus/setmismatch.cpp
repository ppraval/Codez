#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,2,2,4};
    vector<int> ans;
    int n = nums.size();
    unordered_map<int,int> mp;
    for(int i = 1; i <= n; i++)
        mp[i]++;
    for(auto a :nums)
        mp[a]--;
    int duplicate = 0, missing = 0;

    for(auto a :mp)
    {
        if(a.second == -1)
            duplicate = a.first;
        if(a.second == 1)
            missing = a.first;
    }
    ans.push_back(duplicate);
    ans.push_back(missing);
    for(int x : ans)
        cout << x << " ";
    return 0;
}