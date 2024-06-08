#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {23,2,4,6,7};
    int k = 6;
    int sum = 0;
    int count = 0;
    unordered_map<int, int> mp;
    for(int i : nums)
    {
        sum = (sum + i) % k;
        if(sum < 0)
            sum += k;
        count += mp[sum];
        mp[sum]++;
    }
    return 0;
}