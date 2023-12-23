#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 1, 3, 3 ,2, 42};
    int j = 0;
    int n = nums.size();
    if(n == 1)
    {
        return 1;
    }
    for(int i = 0; i < n - 1; i++)
    {
        if(nums[i] != nums[i + 1])
        {
            nums[j++] = nums[i];
        }
    }
    if(nums[n - 1] != nums[n - 2])
    {
        nums[j++] = nums[n - 1];
    }
    for(int i = 0; i < j; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n" << j;
    return 0;
}