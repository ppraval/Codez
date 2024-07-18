#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,30,2,3,50};
    vector<int> index;
    int n = nums.size();
    int j = 0;  
    vector<bool> diff(n, false);
    for(int i = 0; i < n; i++)
    {
        if(nums[i] > n)
        {
            index.push_back(i);
        }
        else
        {
            diff[nums[i] - 1] = true;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(diff[i] == false)
        {
            nums[index[j++]] = i + 1;
        }
    }
    for(int i : nums)
        cout << i << " ";
    return 0;
}