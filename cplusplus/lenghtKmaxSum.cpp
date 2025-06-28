#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k = 3;
    vector<int> nums = {-1,-2,3,4};
    vector<int> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i = n - k; i < n; i++)
    {
        ans.push_back(nums[i]);
    }
    for(int i : ans)
        cout << i << " ";
    return 0;
}