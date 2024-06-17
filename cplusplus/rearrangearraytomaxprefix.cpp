#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {2,-1,0,1,-3,3,-3};
    long long int sum = 0;
    int ans = 0;
    sort(nums.begin(), nums.end(), greater<int>());
    for(int i : nums)
    {
        sum += i;
        if(sum <= 0)
        {
            cout << ans;
            return ans;
        }
        ans++;
    }
    cout << ans;
    return ans;
}