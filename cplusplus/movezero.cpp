#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    int j = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] != 0)
        {
            nums[j++] = nums[i];   
        }
    }
    while(j < nums.size())
    {
        nums[j++] = 0;
    }
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}