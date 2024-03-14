#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int n = nums.size();
    if(n <= 2)
    {
        cout << 0 << endl;
        return 0;
    }
    int diff = nums[1] - nums[0];
    int i = 2;
    int ans = 0;
    int j = 2;
    while(i < n)
    {
        if(nums[i] - nums[i - 1] == diff)
        {
            j++;
        }
        else
        {
            j = 2;
            diff = nums[i] - nums[i - 1];
        }
        if(j >= 3)
        {
            ans += j - 2;
            cout << ans << endl;
        }
        i++;
    }
    cout << ans << endl;
    return ans;
}