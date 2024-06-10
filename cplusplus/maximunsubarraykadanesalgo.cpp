#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int max_sum = INT_MIN;
    int curr_sum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        curr_sum += nums[i];
        max_sum = max(max_sum, curr_sum);
        if(curr_sum < 0)
        {
            curr_sum = 0;
        }
        cout << max_sum << endl;
    }
    return max_sum;
}