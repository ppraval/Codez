#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    int n = nums.size();
    if(n == 1) 
    {
        cout << 0 << endl;
        return 0;
    }
    if(nums[0] > nums[1]) 
    {
        cout << 0 << endl;
        return 0;
    }
    if(nums[n - 1] > nums[n - 2]) 
    {            
        cout << n - 1 << endl;
        return n - 1;
    }

    int low = 1, high = n - 2;
    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) 
        {
            cout << mid << endl;
            return mid;
        }
        else if(nums[mid] < nums[mid + 1])
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    cout << -1 << endl;
    return -1;
}