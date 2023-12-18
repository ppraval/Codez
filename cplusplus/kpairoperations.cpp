#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,2,3,4};
    int k = 5;
    sort(nums.begin(), nums.end());
    int count = 0;
    int i = 0;
    int j = nums.size() - 1;
    while(i < j)
    {
        int sum = nums[i] + nums[j];
        if(sum == k) 
        {
            count++;
            i++;
            j--;
        }
        else if (sum > k) 
            j--;
        else 
            i++;
    }
    cout << "The count is: " << count;
    return 0;
}