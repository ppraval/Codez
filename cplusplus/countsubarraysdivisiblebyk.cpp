#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;
    int count = 0;
    int sum = 0;
    unordered_map<int, int> mp;
    mp[0]++;
    for(int i : nums)
    {
        sum = (sum + i) % k;
        cout << "sum = " << sum << endl;
        if(sum < 0)
            sum += k;
        count += mp[sum];
        cout << count << endl;
        mp[sum]++;
    }
    return count;
}