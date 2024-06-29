#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {0,1,1,0,1};
    int flag = 1;
    int count = 0, n = nums.size();
    for(int i = 0; i < n; i++)
    {
        if(nums[i] != flag)
        {
            count++;
            flag = !flag;
        }
    }
    cout << count;
    return count;
}