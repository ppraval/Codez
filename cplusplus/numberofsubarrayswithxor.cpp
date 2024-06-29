#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> A = {4, 2, 2, 6, 4};
    int B = 6;
    unordered_map<int, int> mp;
    int xor_sum = 0;
    int count = 0;
    mp[xor_sum]++;
    for(int i : A)
    {
        xor_sum ^= i;
        count += mp[xor_sum ^ B];
        mp[xor_sum]++;
    }
    cout << count;
    return count;
}