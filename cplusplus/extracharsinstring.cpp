#include<bits/stdc++.h>
using namespace std;

int find(string s, unordered_map<string, int>& mp, vector<int>& dp, int i, int n)
{
    if(i >= n)
    {
        return 0;
    }
    if(dp[i] != -1)
    {
        return dp[i];
    }

    string substr = "";
    int min_extra = n;
    for(int j = i; j < n; j++)
    {
        substr += s[j];
        cout << substr << endl;
        int curr_extra;
        if(mp.count(substr) )
        {
            curr_extra = 0;
        }   
        else
        {
            curr_extra = substr.length();
        }
        int next_extra = find(s, mp, dp, j + 1, n);
        int total_extra = curr_extra + next_extra;
        min_extra = min(min_extra, total_extra);
    }
    return dp[i] = min_extra;
}


int main()
{
    string s = "leetscode";
    vector<string> dic = {"leet","code","leetcode"};
    vector<int> dp(s.size(), -1);
    int n = s.length();
    unordered_map<string, int> mp;
    for(auto x : dic)
    {
        mp[x]++;
    }
    int ans = find(s, mp, dp, 0, n);
    cout << ans << endl;
    return 0;
}