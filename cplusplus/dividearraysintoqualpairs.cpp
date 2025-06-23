#include<bits/stdc++.h>
using namespace std;

// int main()
// {
//     vector<int> nums = {3,2,3,2,2,2};
//     unordered_map<int, int> mp;
//     for(int i : nums)
//         mp[i]++;
//     for(auto it : mp)
//     {
//         if(it.second % 2 != 0)
//         {
//             cout << "false" << endl;
//             return 0;
//         }
//     }
//     cout << "true" << endl;
//     return 1;
// }

int main()
{
    vector<int> nums = {3,2,3,2,2,2};
    int sum = 0;
    for(int i : nums)
        sum ^= i;
    if(sum == 0)
        return 1;
    else    
        return 0; 
}