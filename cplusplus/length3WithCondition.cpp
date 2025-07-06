#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {-1,-4,-1,4};
    int n = nums.size();
    int count = 0;
    for(int i = 1; i + 1 < n; i++)
    {
        float sum = float(nums[i - 1] + nums[i + 1]);
        float half = float(nums[i]) / 2;
        if(sum == half)
        {
            count++;
        }
    }
    cout << count << endl;
    return count;
}