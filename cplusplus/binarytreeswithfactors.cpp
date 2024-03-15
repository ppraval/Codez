#include<bits/stdc++.h>
using namespace std;
 
 int main()
 {
    // vector<int> arr = {2, 4, 5, 10};
    vector<int> arr = {18, 3, 6, 2};
    int n = arr.size();
    const int mod = 1e9 + 7;
    if(n == 1)
    {
        return 1;
    }
    sort(arr.begin(), arr.end());

    unordered_map<int, long long int> mp;

    for(int i = 0; i < n; i++)
    {
        mp[arr[i]] = 1;
    }

    for(int i = 1; i < n; i++)
    {
        int sqrt_i = sqrt(arr[i]);
        // cout << "How many times do we see this?" << endl;
        for(int j = 0; j <= sqrt_i; j++)
        {
            if(arr[i] % arr[j] == 0 && mp.find(arr[i] / arr[j]) != mp.end())
            {
                if(arr[i] / arr[j] == arr[j])
                {
                    mp[arr[j]] += (mp[arr[i]] * mp[arr[i]] / mp[arr[j]]);
                }
                else
                {
                    mp[arr[j]] += (mp[arr[i]] * mp[arr[i]] / mp[arr[j]]) * 2;
                }
            }
        }
    }

    long long int ans = 0;
    for(auto x : mp)
    {
        ans += x.second;
    }
    cout << ans % mod << endl;
    return ans % mod;
 }