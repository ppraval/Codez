#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {2,3,-1,8,4};
    //find pivot index
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int leftSum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(leftSum == totalSum - leftSum - nums[i])
        {
            cout << "Pivot index: " << i << endl;
            return 0; // Found the pivot index
        }
        leftSum += nums[i];
    }
    cout << "No pivot index found" << endl;
    return 0;
}