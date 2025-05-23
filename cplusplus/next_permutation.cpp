#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,2,3};
    int index = -1;
    int n = nums.size();
    for(int i = n - 2; i >= 0; i--)
    {
        if(nums[i] < nums[i + 1])
        {
            index = i;
            break;
        }
    }
    if(index == -1)
    {
        reverse(nums.begin(), nums.end());
        for(int i : nums)
            cout << i << " ";
        return 0;
    }
    for(int i = n - 1; i > index; i--)
    {
        if(nums[i] > nums[index])
        {
            swap(nums[i], nums[index]);
            break;
        }
    }
    reverse(nums.begin() + index + 1, nums.end());
    for(int i : nums)
        cout << i << " ";
    return 0;
}