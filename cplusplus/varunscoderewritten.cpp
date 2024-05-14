#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,2,4};
    int k = 5;
    vector<int> v;
    sort(nums.begin(), nums.end());
    map<int, int> mp;
    for(int i : nums)
    {
        mp[i]++;
    }
    int max_freq = INT_MIN;
    for(auto x : mp)
    {
        max_freq = max(max_freq, x.second);
        v.push_back(x.first);
    }
    for(int i : v)
    {
        int count = 1;
        multiset<int> s;
        int l = k;
        for(int j : nums)
        {
            if(i > j)
            {
                s.insert(i - j);
            }
        }
        for(int j : s)
        {
            // cout << j << endl;
            if(l >= j)
            {
                l -= j;
                count++;
                // cout << "count = " << count << " j = " << j << endl;
            }
            else
            {
                break;
            }
        }
        max_freq = max(count, max_freq);
    }
    cout << max_freq << endl;
    return 0;
}