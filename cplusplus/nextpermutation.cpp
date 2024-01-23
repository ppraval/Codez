#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3};
    next_permutation(nums.begin(), nums.end());
    for(int x : nums)
        cout << x << " "; 
    return 0;
}