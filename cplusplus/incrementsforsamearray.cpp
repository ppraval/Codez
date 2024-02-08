#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, 4};
    int min = *min_element(nums.begin(), nums.end());
    int sum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i] - min;
    }
    cout << sum << endl;
    return 0;
}