#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "badc";
    string t = "baba";
    unordered_map<char, char> mp, mp2;
    for(int i = 0; i < s.length(); i++) 
    {
        if (mp[s[i]] && mp[s[i]] != t[i]) 
            cout << false;
        if (mp2[t[i]] && mp2[t[i]] != s[i]) 
            cout << false;
        mp[s[i]] = t[i];
        mp2[t[i]] = s[i];
    }
    cout << true;
    return 0;
}