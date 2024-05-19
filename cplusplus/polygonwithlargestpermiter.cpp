#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {5,5,5};
    sort(nums.begin(), nums.end());
    int n = nums.size();
    long long ans = 0, sum = nums[0] + nums[1];
    for(int i = 2; i < n; i++)
    {
        if(sum > nums[i])
        {
            ans = sum + nums[i];
        }
        sum += nums[i];
    }
    cout << ans << endl;
    return 0;
}