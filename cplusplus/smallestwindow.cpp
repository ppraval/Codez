#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "geeksforgeeks";
    string t = "ork";
    unordered_map<int, int> mp, mp2;
    for(auto x : t)
        mp[x]++;
    int k = t.length();
    for(int i = 0; i < k; i++)
    {
        mp2[s[i]]++;
    }
    for(int i = k; i < s.length(); i++)
    {
        
    }
    return 0;
}