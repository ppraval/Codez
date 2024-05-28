#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "acfgbd";
    int k = 2;
    vector<int> dp (26, 0);
    for(char ch : s)
    {
        int i = ch - 'a';
        int start = max(0, i - k);
        int end = min(25, i + k);
        for(int j = start; j <= end; j++)
        {
            dp[i] = max(dp[i], dp[j]);
        }
        dp[i]++;
    }
    cout << *max_element(dp.begin(), dp.end());
    return *max_element(dp.begin(), dp.end());
}