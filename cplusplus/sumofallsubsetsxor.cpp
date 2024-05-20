#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> nums, int i, int n, int element, int& total_sum)
{
    if(i == n)
    {
        total_sum += element;
        return;
    }
    dfs(nums, i + 1, n, element, total_sum);
    dfs(nums, i + 1, n, element ^ nums[i], total_sum);
}

int main()
{
    vector<int> nums = {1,3};
    int n = nums.size();
    int total_sum = 0;
    dfs(nums, 0, n, 0, total_sum);
    cout << total_sum << endl;
    return total_sum;
}