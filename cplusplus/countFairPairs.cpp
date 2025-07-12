#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0;

        for (int i = 0; i < nums.size(); ++i) 
        {
            int l = lower - nums[i];
            int r = upper - nums[i];
            
            auto left = lower_bound(nums.begin() + i + 1, nums.end(), l);
            auto right = upper_bound(nums.begin() + i + 1, nums.end(), r);
            count += distance(left, right);
        }
        return count;
    }
};

int main() 
{
    Solution sol;
    vector<int> nums1 = {0, 1, 7, 4, 4, 5};
    int lower1 = 3, upper1 = 6;
    cout << sol.countFairPairs(nums1, lower1, upper1) << endl; // Output: 6

    vector<int> nums2 = {1, 7, 9, 2, 5};
    int lower2 = 11, upper2 = 11;
    cout << sol.countFairPairs(nums2, lower2, upper2) << endl; // Output: 1

    return 0;
}