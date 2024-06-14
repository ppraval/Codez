#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {3,2,1,2,1,7};
    sort(nums.begin(),nums.end());
    int ans = 0;
    for(int i=1; i < nums.size(); i++)
    {

        if(nums[i] <= nums[i - 1])
        {
            ans += nums[i - 1] - nums[i] + 1;
            nums[i] = nums[i - 1] + 1;
        }
    }
    cout << ans;
    return ans;
}