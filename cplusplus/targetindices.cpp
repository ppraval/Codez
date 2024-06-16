#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,2,5,2,3};
    int k = 2;
    vector<int> ans;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == k)
        {
            ans.push_back(i);
        }
    }
    for(int i : ans)
        cout << i << " ";
    return 0;
}