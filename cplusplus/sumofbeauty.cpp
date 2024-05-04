#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,2,3,5,4};
    int n = nums.size(), ans = 0;
    vector<int> prefix (n, INT_MIN), suffix(n, INT_MAX);
    prefix[0] = nums[0], suffix[n - 1] = nums[n - 1];
    for(int i = 1; i < n; i++)
    {
        prefix[i] = max(nums[i], prefix[i - 1]);
    }
    for(int i = n - 2; i >= 0; i--)
    {
        suffix[i] = min(nums[i], suffix[i + 1]);
    }
    for(int i : prefix)
        cout << i << " ";
    cout << endl;
    for(int i : suffix)
        cout << i << " ";
    cout << endl;
    for(int i = 1; i < n - 1; i++)
    {
        if(nums[i] < suffix[i + 1] && nums[i] > prefix[i - 1])
        {
            ans += 2;
        }
        else if(nums[i] < nums[i + 1] && nums[i - 1] < nums[i])
        {
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}