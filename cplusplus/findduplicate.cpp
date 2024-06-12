#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,3,4,2,2};
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == nums[i + 1])
        {
            cout << nums[i];
            return nums[i];
        }
    }
    return 0;
}