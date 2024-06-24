#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {11,21,12};
    int ans = 0, n = nums.size();
    for(int i = 0; i < n; i++)
    {
        string one = to_string(nums[i]), two; 
        int num1 = one[0] - '0', num2;
        for(int j = i + 1; j < n; j ++)
        {
            two = to_string(nums[j]);
            num2 = two.back() - '0';
            if(gcd(num1, num2) == 1)
                ans++;
        }
    }
    cout << ans;
    return ans;
}