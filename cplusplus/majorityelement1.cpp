#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,1,2,3,2,4};
    int count = 0;
    int ele = nums[0];
    for(int i = 0; i < nums.size(); i++)
    {
        if(count == 0)
        {
            ele = nums[i];
        }
        if(ele == nums[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    cout << ele << endl;
    return 0;
}