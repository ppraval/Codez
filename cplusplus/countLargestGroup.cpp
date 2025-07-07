#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 13;
    int ans = 0;
    int maxCount = 0;
    unordered_map<int, int> mp;
    for(int i = 1; i <= n; i++)
    {
        int sum = 0;
        int num = i;
        while(num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        mp[sum]++;
        maxCount = max(maxCount, mp[sum]);
    }
    for(auto i : mp)
    {
        if(i.second == maxCount)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return ans;
}