#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,3,4,2,2};
    vector<int> map (nums.size(), 0);
    for(int i = 0; i < nums.size(); i++)
    {
        if(map[nums[i] - 1] != 0)
        {
            cout << nums[i] << endl;
            return nums[i];
        }
        map[nums[i] -1]++;
    }
    return 0;
}