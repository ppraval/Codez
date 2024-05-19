#include<bits/stdc++.h>
using namespace std;

int main()
{   
    vector<int> nums = {2,1,4};
    for (int i = 0; i < nums.size() - 1; ++i) 
    {
        if ((nums[i] % 2 == 0 && nums[i + 1] % 2 == 0) || (nums[i] % 2 != 0 && nums[i + 1] % 2 != 0)) 
        {
            return false;
        }
    }
    return true;
}