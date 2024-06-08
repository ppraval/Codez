#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1,1,1};
    int k = 2;
    int count = 0;
    int sum = 0;
    unordered_map<int, int> mp;
    mp[0]++;
    for(int i : arr)
    {
        sum += i;
        count += mp[sum - k];
        mp[sum]++;
    }
    cout << count << endl;
    return count;
}