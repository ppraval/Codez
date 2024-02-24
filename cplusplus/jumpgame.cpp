#include<bits/stdc++.h>
using namespace std;

int main()
{
    // vector<int> nums = {2, 3, 1, 1, 4};
    vector<int> nums = {3,2,1,0,4};
    int max_index = nums[0];
    for (int i = 0; i < nums.size(); i++) 
    {
        if (max_index >= nums.size() - 1) 
        {
            cout << true << endl;
            return true;
        }
        if (nums[i] == 0 and max_index == i) 
        {
            cout << false << endl;
            return false;
        }
        if (nums[i] + i > max_index) 
            max_index = nums[i] + i;
    }
    cout << true << endl;
    return true;
}