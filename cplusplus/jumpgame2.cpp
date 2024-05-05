#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {2,3,1,1,4};
    int n = nums.size();
    int step = nums[0], max_range = nums[0];
    int ans = 1;
    if(n <= 1)
        return 0;
    if(step == 0)
        return -1;
    for(int i = 1; i < n; i++)
    {
        if(i == n - 1)
        {
            cout << ans;
            return ans;
        }
        max_range = max(max_range, nums[i] + i);
        step--;
        if(step == 0)
        {
            ans++;
            if(max_range <= i)
                return -1;
            step = max_range - i;   
        }
    }   
    return -1;
}