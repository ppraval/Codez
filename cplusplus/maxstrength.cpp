#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {3,-1,-5,2,5,-9};
    int n = nums.size();
    vector<int> neg;
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(nums[i] > 0)
        {
            if(ans == 0)
            {
                ans = nums[i];
            }
            else
            {
                ans *= nums[i];
            }
        }
        else if(nums[i] < 0)
        {
            neg.push_back(nums[i]);
        }
    }
    cout << ans << endl;
    sort(neg.begin(), neg.end());
    for(int i : neg)
        cout << i << " ";
    cout << endl;
    n = neg.size();
    if(n % 2 == 0)
    {
        for(int i = 0; i < n; i++)
        {
            if(ans == 0)
            {
                ans = neg[i];
            }
            else
            {
                ans *= neg[i];
            }
        }
    }
    if(n % 2 == 1)
    {
        for(int i = 0; i < n - 1; i++)
        {
            if(ans == 0)
            {
                ans = neg[i];
            }
            else
            {
                ans *= neg[i];
            }
        }
    }
    cout << ans << endl;
    return 0;
}