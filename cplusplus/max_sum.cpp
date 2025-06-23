#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {10, 20, 30, 5, 10, 50};
    int max_sum = INT_MIN;
    int n = nums.size();
    int current_sum = 0;
    for(int i = 0; i < n; i++)
    {
        current_sum += nums[i];
        if(i == n - 1)
        {
            max_sum = max(max_sum, current_sum);
            break;
        }
        if(!(nums[i] < nums[i + 1]))
        {
            max_sum = max(max_sum, current_sum);
            current_sum = 0;
        }
    }
    cout << max_sum << endl;
    return 0;
}