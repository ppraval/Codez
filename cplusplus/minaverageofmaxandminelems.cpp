#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {7,8,3,4,15,13,4,1};
    int l = 0, r = nums.size() - 1;
    int ans = INT_MAX;
    sort(nums.begin(), nums.end());
    while(l < r)
    {
        ans = min(ans, (nums[l] + nums[r]) / 2);
        r--;
        l++;
    }
    cout << ans;
    return 0;
}