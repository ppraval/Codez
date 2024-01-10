#include<bits/stdc++.h>
using namespace std;

// int main()
// {
//     vector<int> nums = {1,2,3,4,5,6,7};
//     int k = 3;
//     int n = nums.size();
//     while(k--)
//     {
//         int temp = nums[n - 1];
//         for(int i = n - 1; i >= 0; i--)
//         {
//             if(i == 0)
//             {
//                 nums[0] = temp;
//             }
//             else
//             {
//                 nums[i] = nums[i - 1];
//             }
//         }
//     }
//     for(auto x : nums)
//     {
//         cout << x << " ";
//     }
//     return 0;
// }

int main()
{
    vector<int> nums = {-1,-100,3,99};
    int k = 2;
    int n = nums.size();
    vector<int> copy = nums;
    for(int i = n - 1; i >= 0; i--)
    {
        nums[(i + k) % n] =  copy[i];
    }
    for(auto x : nums)
        cout << x << " ";
    return 0;
}