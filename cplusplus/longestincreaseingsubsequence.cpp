#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = nums.size();
    vector<int> dp(n, 1);
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        for(int i : dp)
            cout << i << " ";
        cout << endl;
        cout << endl;
    }
    int ans = *max_element(dp.begin(), dp.end());
    cout << ans << endl;
    return 0;
}