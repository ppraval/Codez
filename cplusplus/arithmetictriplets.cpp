#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {0,1,4,6,7,10};
    int diff = 3;
    int count = 0;
    unordered_set<int> s(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++)
    {
        if(s.count(nums[i] + diff) && s.count(nums[i] + (2 * diff)))
        {
            count++;
        }
    }
    cout << count;
    return count;
}