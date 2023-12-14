#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {2, 1, 5, 0, 4, 5};
    int n = nums.size();
    int min = INT_MAX;
    int mid = INT_MAX;

    if(n < 3)
    {
        cout << "False";
        return 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        if(mid < nums[i])
        {
            cout << "True";
            return 0;
        }
        else if (min < nums[i] && mid > nums[i])
        {
            mid = nums[i];
        }
        else if (nums[i] < min)
        {
            min = nums[i];
        }
    }

    cout << "False";
    return 0;
}