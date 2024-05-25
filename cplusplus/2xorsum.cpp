#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,2,1,3};
    unordered_map<int, int> mp;
    int sum = 0;
    for(int i : nums)
        mp[i]++;
    for(auto x : mp)
    {
        if(x.second == 2)
        {
            sum ^= x.first;
        }
    }
    cout << sum << endl;
    return sum;
}