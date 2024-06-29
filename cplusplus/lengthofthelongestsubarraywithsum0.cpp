#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {15,-2,2,-8,1,7,10,23};
    int max_i = 0;
    int sum = 0;
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if(sum == 0)
        {
            max_i = i + 1;
        }
        else
        {
            if(mp.find(sum) != mp.end())
            {
                max_i = max(max_i, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
    }
    cout << max_i;
    return max_i;
}