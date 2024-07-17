#include<bits/stdc++.h>
using namespace std;

void sub(vector<int> nums, int i, int n, vector<vector<int>> &v, vector<int> temp)
{
    if(i >= n)
    {
        v.push_back(temp);
        return;
    }
    temp.push_back(nums[i]);
    sub(nums, i + 1, n, v, temp);
    temp.pop_back();
    sub(nums, i + 1, n, v, temp);
}


int main()
{
    vector<int> nums = {13,5,1,8,21,2};
    int k = 3;
    vector<vector<int>> v;
    vector<int> temp;
    int min_val;
    int max_val = INT_MIN;
    sub(nums, 0, nums.size(), v, temp);
    for(auto x : v)
    {
        if(x.size() == k)
        {
            min_val = min({abs(x[0] - x[1]), abs(x[0] - x[2]), abs(x[1] - x[2])});
            max_val = max(max_val, min_val);
        }
    }
    cout << max_val;
    return 0;
}