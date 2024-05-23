#include<bits/stdc++.h>
using namespace std;

void backtracking(vector<int> nums, int i, int k, unordered_map<int, int>& mp, int n, int& count)
{
    if(i >= n)
    {
        count++;
        return;
    }
    int val = nums[i];
    if(mp.find(val - k) == mp.end() && mp.find(val + k) == mp.end())
    {
        mp[val]++;
        backtracking(nums, i + 1, k, mp, n, count);
        mp[val]--;
        if(mp[val] == 0)
        {
            mp.erase(val);
        }
    }
    backtracking(nums, i + 1, k, mp, n, count);
}

int main()
{
    vector<int> nums = {2,4,6};
    int k = 2;
    int count = 0;
    unordered_map<int, int> mp;
    backtracking(nums, 0, k, mp, nums.size(), count);
    cout << count - 1 << endl;
    return count - 1;
}