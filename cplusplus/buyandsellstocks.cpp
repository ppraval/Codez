#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {7,1,5,3,6,4};
    int min_price = nums[0];
    int max_prof = 0;
    for(int i = 1; i < nums.size(); i++)
    {
        max_prof = max(max_prof, nums[i] - min_price);
        min_price = min(min_price, nums[i]);
    }
    cout << max_prof;
    return 0;
}