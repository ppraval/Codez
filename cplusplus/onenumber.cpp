#include<bits/stdc++.h>
using namespace std;

// standard code with unordered maps 
// int main()
// {
//     vector<int> nums = {2,2,1};
//     unordered_map<int, int> a;
//     for(int x : nums)
//         a[x]++;
//     for(auto z : a)
//         if(z.second == 1)
//         {
//             cout << z.first;
//             return z.first;
//         }
//     cout << -1;
//     return -1;
// }

// better code with XOR
int main()
{
    vector<int> nums = {2,2,1};
    for(int i = 1;i < nums.size(); i++)
    {
        nums[0] = nums[0] ^ nums[i];
    }
    cout << nums[0];
    return nums[0];
}