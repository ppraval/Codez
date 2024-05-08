#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,2,3,2};
    unordered_map<int, int> mp;
    for(int i : nums)
        mp[i]++;
    int sum = 0;
    for(auto x : mp)
    {
        if(x.second == 1)
        {
            sum += x.first;
        }
    }
    cout << sum << endl;
    return sum;
}