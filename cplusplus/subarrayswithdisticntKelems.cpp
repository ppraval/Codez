#include<bits/stdc++.h>
using namespace std;

int subArraysWithKElems(vector<int> nums, int k)
{
    int i = 0, j = 0;
    int n = nums.size();
    int count = 0;
    unordered_map<int, int> mp;
    while(j < n)
    {
        mp[nums[j]]++;
        while(i <= j && mp.size() > k)
        {
            if(--mp[nums[i]] == 0)
                mp.erase(nums[i]);      
            i++;
        }
        count += j - i + 1;
        j++;
    }
    return count;
}

int main()
{
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << subArraysWithKElems(nums, k) - subArraysWithKElems(nums, k - 1);
    return subArraysWithKElems(nums, k) - subArraysWithKElems(nums, k - 1);
}