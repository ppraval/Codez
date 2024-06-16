#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,3};
    int n = 6;
    long long miss = 1;
    int ans = 0;
    long long i = 0;
    while(miss <= n)
    {
        if(i < nums.size() && nums[i] <= miss)
        {
            miss += nums[i];
            i++;
        }
        else
        {
            miss += miss;
            ans++;
        }
    }
    cout << ans;
    return ans;
}