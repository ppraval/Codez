#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {2,3,-2,4};
    int n = nums.size();
    int ans = INT_MIN;
    int pre = 1;
    int suf = 1;
    for(int i = 0; i < n; i++)
    {
        if(pre == 0)
            pre = 1;
        if(suf == 0)
            suf = 1;
        pre *= nums[i];
        suf *= nums[n - i + 1];
        ans = max(ans, max(pre, suf));
    }
    cout << ans;
    return 0;
}