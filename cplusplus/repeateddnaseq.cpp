#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> ans;
    int l = 0, r = 9;
    unordered_map<string, int> mp;
    string s1 = "";
    while(l < s.length())
    {
        s1 = s.substr(l, r - l + 1);
        mp[s1]++;
        if(mp[s1] == 2)
        {
            ans.push_back(s1);
        }
        l++;
        r++;
    }
    for(auto x : ans)
        cout << x << " ";
    return 0;
}