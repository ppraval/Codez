#include<bits/stdc++.h>
using namespace std;

int multiplyArray(vector<int> nums)
{
    int product = 1;
    for(int i = 0; i < nums.size(); i++)
    {
        product *= nums[i];
    }
    return product;
}

int main()
{
    vector<int> nums = {-1, 1, 0, -3, 3};
    vector<int> temp = nums;
    for(int i = 0; i < nums.size(); i++)
    {
        int temp_num = nums[i];
        temp.erase(temp.begin() + i);
        nums[i] = multiplyArray(temp);
        temp.emplace(temp.begin() + i, temp_num);
    }

    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}