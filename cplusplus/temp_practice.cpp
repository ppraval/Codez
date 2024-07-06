#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {4,2,2,6,4};
    int sum = 0;
    int count = 0;
    int b = 6;
    unordered_map<int, int> mp;
    mp[sum]++;
    for(int i : nums)
    {
        sum ^= i;
        count += mp[sum ^ b];
        mp[sum]++;
    }
    cout << count;
    return 0;
}