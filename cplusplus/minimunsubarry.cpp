#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int ans = INT_MAX;
    int i = 0, j = 0, n = nums.size();
    long long sum = 0;
    while(j < n)
    {
        sum += nums[j];
        while(sum >= target)
        {
            ans = min(ans, j - i + 1);
            sum -= nums[i++];
        }
        j++;
    }
    cout << ans << endl;
    return 0;
}