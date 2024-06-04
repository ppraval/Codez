#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    int n = nums.size();
    vector<int> ans;
    vector<int> temp(n, 0);
    for(int i = 0; i < n; i++)
    {   
        temp[nums[i] - 1]++;
    }
    for(int i = 0; i < n; i++)
    {
        if(temp[i] == 0)
            ans.push_back(i + 1);
    }
    for(int i : ans)
        cout << i << " ";
    return 0;
}