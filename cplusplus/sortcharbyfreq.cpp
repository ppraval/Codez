#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "tree";
    unordered_map<char, int> mp;
    multimap<int, char> mmap;
    string ans = "";
    for(auto ch : s)
    {
        mp[ch]++;
    }
    for(auto x : mp)
    {
        mmap.insert({x.second, x.first});
    }
    for(auto i = mmap.rbegin(); i != mmap.rend(); i++)
    {
        ans += string(i->first, i->second);
    }
    cout << ans << endl;
    return 0;
}