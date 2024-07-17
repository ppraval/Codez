#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {7,1,5,3,6,4};
    int min_price = nums[0];
    int sum = 0;
    for(int i = 1; i < nums.size(); i++)
    {
        if(min_price < nums[i])
        {
            sum += nums[i] - min_price;
        }
        min_price = nums[i];
    }
    cout << sum;
    return sum;
}