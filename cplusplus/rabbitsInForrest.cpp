#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 1, 2};
    unordered_map<int, int> mp;
    for(int i : v)
        mp[i]++;
    int ans = 0;
    for(auto& [k, count] : mp)
    {
        int group_size = k + 1;
        int groups = (count + k) / group_size;
        ans += groups * group_size;
    }
    cout << ans << endl;
    return 0;
}