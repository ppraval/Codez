#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {2,1,3,4};
    int k = 1;
    int xor_sum = 0;
    for(int i : nums)
        xor_sum ^= i;
    int count = 0;
    while(k || xor_sum)
    {
        if(k % 2 != xor_sum % 2)
            count++;
        k /= 2;
        xor_sum /= 2;
    }
    cout << count;
    return count;
}