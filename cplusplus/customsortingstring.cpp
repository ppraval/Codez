#include<bits/stdc++.h>
using namespace std;

int main()
{
    string order = "cba";
    string s = "abcd";
    string ans = "";
    unordered_map<char, int> mp;
    for (char c : order) 
    {
        mp[c] = 0;
    }
    for (char c : s) 
    {
        if (mp.find(c) != mp.end()) 
        {
            mp[c]++;
        }
    }
    
    for (char c : order) 
    {
        ans.append(mp[c], c);
        cout << ans << endl;
    }
    for (char c : s) 
    {
        if (mp.find(c) == mp.end()) 
        {
            ans.push_back(c);
        }
    }
    cout << ans << endl;
    return 0;
}