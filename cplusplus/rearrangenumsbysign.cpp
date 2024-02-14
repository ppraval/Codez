#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {-1, 1};
    vector<int> pos;
    vector<int> neg;
    int n = nums.size();
    int j = 0, k = 0;
    for(int i = 0; i < n; i++)
    {
        if(nums[i] > 0)
            pos.push_back(nums[i]);
        else
            neg.push_back(nums[i]);
    }
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
            nums[i] = pos[j++];
        else
            nums[i] = neg[k++];
    }
    for(int x : nums)
        cout << x << " ";
    return 0;
}