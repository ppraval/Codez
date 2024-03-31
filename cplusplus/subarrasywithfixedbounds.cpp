#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,3,5,2,7,5};
    int minK = 1, maxK = 5;
    long long ans = 0;
    int leave = -1, left = -1, right = -1;

    for(int i = 0; i < nums.size(); i++)
    {
        if(!(minK <= nums[i] && nums[i] <= maxK))
        {
            leave = i;
            cout << "leave = " << leave << endl;
        }
        if(nums[i] == minK)
        {
            left = i;
            cout << "left = " << left << endl;
        }
        if(nums[i] == maxK)
        {
            right = i;
            cout << "right = " << right << endl;
        }
        ans += max(0, min(left, right) - leave);
        cout << endl;
    }
    cout << ans;
    return 0;
}