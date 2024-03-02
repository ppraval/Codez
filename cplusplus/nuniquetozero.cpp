#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 2;
    vector<int> nums(n);
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(i != n - 1)
        {
            nums.push_back(i + 1);
            sum += nums[i];
        }
        else
        {
            nums.push_back(-1 * sum);
        }
    }
    for(int i : nums)
        cout << i << " ";
    return 0;
}