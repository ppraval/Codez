#include<bits/stdc++.h>
using namespace std;


int main()
{
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {2, 4};

    unordered_map<int, int> mp;
    for(int i : nums1)
    {
        if(mp[i] == 1)
            continue;
        mp[i]++;
    }
    for(int i : nums2)
        mp[i]++;
    int min_element = INT_MAX;
    for(auto k : mp)
    {
        if(k.second > 1)
        {
            min_element = min(k.first, min_element);
        }
    }
    if(min_element != INT_MAX)
        cout << min_element << endl;
    else
        cout << -1 << endl;
    return 0;
}