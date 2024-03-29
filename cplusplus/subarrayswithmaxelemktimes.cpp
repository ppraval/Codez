#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 3, 2, 3, 3};
    int k = 2;
    
    int l = 0, r = 0, count = 0;
    int n = nums.size();
    long long ans = 0;
    int max_elem = *max_element(nums.begin(), nums.end());
    
    while(r < n)
    {
        if(nums[r] == max_elem)
        {
            count++;
        }
        while(l <= r && count >= k)
        {
            ans += n - r;
            if(nums[l] == max_elem)
            {
                count--;
            }
            l++;
        }
        r++;
    }
    cout << ans << endl;
    return 0;
}
