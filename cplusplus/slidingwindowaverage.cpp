#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {9,7,3,5,6,2,0,8,1,9};
    int k = 6;
    float sum = 0;
    float average = INT_MAX * -1, current_average = 0;
    if(nums.size() == 1)
        return nums[0];
    sum = accumulate(nums.begin(), nums.begin() + k, 0);
    current_average = sum / k;
    cout << "The sum is : " << sum << "\n";
    if(k == nums.size())
    {
        cout << "Average is :" << current_average;
        return current_average;
    }
    for(int i = 1; i + k < nums.size(); i++)
    {
        if(i + k < nums.size())
        {
            sum = sum - nums[i - 1] + nums[i + k - 1];
            current_average = sum / k;
        }
        if(average <= current_average)
        {
            average = current_average;
            cout << "Current average : " << current_average;
            cout << "\naverage :" << average << "\n";
        }
    }
    cout << "The average is : " << average;
    return 0;
}