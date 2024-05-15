#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    unordered_map<int, int> mp;
    for(int i : nums)
        mp[i]++;
    vector<pair<int, int>> v;
    vector<int> ans;
    for(auto x : mp)
    {
        v.push_back({x.second, x.first});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < k; i++)
    {
        ans.push_back(v[v.size() - i - 1].second);
    }
    for(int i : ans)
        cout << i << " ";
    return 0;
}