#include<bits/stdc++.h>
using namespace std;

    
int main()
{
    vector<int> nums = {1, 1, 1};
    int k = 1;
    int l = 0, r = 0, product = 1, count = 0;
    int n = nums.size();
    if(k <= l)
        return 0;
    while(r < n)
    {
        product *= nums[r++];
        while(l < r && product >= k)
        {
            product /= nums[l++];
        }
        count += r - l;
    }
    cout << count << endl;
    return count;
}