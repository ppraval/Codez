#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {-1,2,1,-4};
    int k = 1;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = -1, diff = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        int l = i + 1, r = n - 1;
        while(l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if(abs(k - sum) < diff)
            {
                ans = sum;
                diff = abs(k - sum);
            }
            if(sum <= k)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}