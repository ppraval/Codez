#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {2,3,6};
    // vector<int> nums = {3, 4, 5, 6, 8, 12};
    // vector<int> nums = {8, 12, 20, 15};
    int n = nums.size();
    vector<int> temp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= nums[i]; j++)
        {
            if(nums[i] % j == 0)
            {
                temp.push_back(j);
            }
        }
    }
    for(int i : temp)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << *max_element(temp.begin(), temp.end());
    return 0;
}