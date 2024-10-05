#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {10,12,13,14};
    vector<string> v;
    for(int i : nums)
    {
        v.push_back(to_string(i));
    }
    int min_ele = INT_MAX;
    for(int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for(int j = 0; j < v[i].length(); j++)
        {
            sum += v[i][j] - '0';
        }
        min_ele = min(sum, min_ele);
        nums[i] = sum;
    }
    cout << min_ele;
    return min_ele;
}