#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {12, 6, 1, 2, 7};
    int n = nums.size();
    vector<int> leftMax(n, 0), rightMax(n, 0);
    for(int i = 0; i < n; i++) 
    {
        if(i == 0) 
            leftMax[i] = nums[i];
        else 
            leftMax[i] = max(leftMax[i-1], nums[i]);
    }
    for(int i = n - 1; i >= 0; i--) 
    {
        if(i == n - 1) 
            rightMax[i] = nums[i];
        else 
            rightMax[i] = max(rightMax[i + 1], nums[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int l = leftMax[i];
        int r = rightMax[i];
        ans = max(ans, (l - nums[i]) * r);
    }
    cout << ans << endl;
    return ans;
}