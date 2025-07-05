#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {-2,-1,-1,1,2,3};
    int pos = 0;
    int neg = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++)
    {
        if(nums[i] > 0)
            pos++;
        else if(nums[i] < 0)
            neg++;
    }
    cout << max(pos, neg);
    return max(pos, neg);
}