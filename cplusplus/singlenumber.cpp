#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,2,1,3,2,5};
    long long x = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        x = x ^ nums[i];
    }
    long long set = x & (-x);
    int a = 0, b = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] & set)
            a ^= nums[i];
        else
            b ^= nums[i];
    }
    cout << a << " " << b << endl;
    return 0;
}