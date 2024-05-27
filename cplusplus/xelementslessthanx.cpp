#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {3, 5};
    sort(nums.begin(), nums.end());
    int r = 0, l = nums.size();
    while(r <= l)
    {
        int mid = r + (l - r) / 2;
        int ans = 0;
        for(int i : nums)
        {
            if(i >= mid)
            {
                ans++;
            }
        }
        if(ans == mid)
        {
            cout << mid << endl;
            return mid;
        }
        else if(ans > mid)
        {
            r = mid + 1;
        }
        else
        {
            l = mid - 1;
        }
    }
    cout << -1 << endl;
    return -1;
}