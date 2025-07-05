#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {2, 3, 4, 6};
    unordered_map<int, int> mp;
    int ans = 0, n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) 
        {
            int product = nums[i] * nums[j];
            ans += 8 * mp[product];
            mp[product]++;
        }   
    }
    cout << ans << endl;
    return ans;
}