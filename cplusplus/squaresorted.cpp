#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {-4,-1,0,3,10};
    for(int i = 0; i < nums.size(); i++)
    {
        nums[i] = nums[i] * nums[i];
    }
    sort(nums.begin(), nums.end());
    for(auto x : nums)
        cout << x << " ";
    return 0;
}