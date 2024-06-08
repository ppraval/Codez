#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,1,4,2,3};
    int x = 5;
    int n = nums.size();
    int sum = 0;
    int count = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    int total_sum = accumulate(nums.begin(), nums.end(), 0);
    int k = total_sum - x;
    for(int i = 0; i < n; i++)
    {
        sum += nums[i];
        if(mp.find(sum - k) != mp.end())
        {
            count = max(count, i - mp[sum - k]);
        }
        if(mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }
    if(count == 0)
        return -1;
    cout << n - count;
    return n - count;
}