#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = size(arr);
    vector<int> dp(n, 1);
    unordered_map<int, int> mp;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j])
            {
                int prev = dp[i];
                dp[i] = max(dp[i], dp[j] + 1);
                if(dp[i] == prev)
                    mp[i] = i;
                else
                    mp[i] = j;
            }
        }
    }
    int temp = INT_MIN;
    int max_i;
    for(int i = 0; i < n; i++)
    {
        if(dp[i] > temp)
        {
            temp = dp[i];
            max_i = i;
        }
    }
    vector<int> ans;
    ans.push_back(arr[max_i]);
    while(mp[max_i] != max_i)
    {
        max_i = mp[max_i];
        ans.push_back(arr[max_i]);
    }
    reverse(begin(ans), end(ans));
    for(int i : ans)
        cout << i << " ";
    // cout << *max_element(begin(dp), end(dp)) << endl;
    return 0;
}