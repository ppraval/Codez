#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 2, 5};
    int ans = 0;
    for (int i = 0; i < 32; i++) 
    {
        int sum = 0;
        for (int num : nums)
        sum += num >> i & 1;
        sum %= 3;
        ans |= sum << i;
    }
    cout << ans;
    return ans;
}