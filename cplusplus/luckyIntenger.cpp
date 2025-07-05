#include <bits/stdc++.h>
using namespace std;

int main() 
{
    vector<int> nums = {2, 2, 3, 4};
    map<int, int> mp;

    for (int i : nums)
        mp[i]++;

    for (auto it = mp.rbegin(); it != mp.rend(); ++it) 
    {
        cout << it->first << " " << it->second << endl;
        if (it->second == it->first) 
        {
            cout << it->first << endl;
            return it->first;
        }
    }
    cout << -1 << endl;
    return -1;
}