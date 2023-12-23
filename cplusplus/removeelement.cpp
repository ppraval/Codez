#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    int j = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] != val)
        {
            nums[j++] = nums[i];
        }
    }
    for(int i = 0; i < j; i++)
    {
        cout << nums[i] << " ";
    }
    return j;
}