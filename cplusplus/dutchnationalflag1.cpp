#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {0,1,2,1,0,0,1};
    int n = nums.size();
    int mid = 0, low = 0, high = n - 1;
    while(mid <= high)
    {
        if(nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
    for(int i : nums)
        cout << i << " ";
    return 0;
}