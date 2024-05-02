#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {-1,10,6,7,-7,1};
    int max_elem = INT_MIN;
    unordered_map<int, int> mp;
    for(int i : nums)
        mp[i]++;
    for(auto i : mp)
    {
        if(mp.find(-1 * i.first) != mp.end())
        {
            max_elem = max(abs(i.first), max_elem);
        }
    }
    if(max_elem == INT_MIN)
        max_elem = -1;
    cout << max_elem << endl;
    return 0;
}