#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {7, 1, 5, 4};
    int n = nums.size();
    int maxDiff = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(nums[i] < nums[j])
            {
                maxDiff = max(maxDiff, nums[j] - nums[i]);
            }
        }
    }
    cout << maxDiff << endl;
    return maxDiff;
}