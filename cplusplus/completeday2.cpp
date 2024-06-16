#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {12,12,30,24,24};
    long long ans = 0;
    unordered_map<int, int> mp;
    for(int i : nums)
    {
        ans += mp[(24 - i % 24) % 24];
        mp[i % 24]++;
    }
    cout << ans;
    return 0;
}