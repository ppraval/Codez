#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int count = 0;
    int max_count = INT_MIN;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 1)
        {
            count++;
            max_count = max(max_count, count);
        }
        else
        {
            count = 0;
        }
    }
    if(max_count == INT_MIN)
    {
        cout << 0;
        return 0;
    }
    else
    {
        cout << max_count;
        return max_count;
    }
}