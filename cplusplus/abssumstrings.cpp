#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abc", t = "bac";
    unordered_map<char, int> mp1, mp2;
    for(int i = 0; i < s.size(); i++)
        mp1[s[i]] = i;
    for(int i = 0; i < s.size(); i++)
        mp2[t[i]] = i;
    int sum = 0;
    for(char x : s)
    {
        sum += abs(mp1[x] - mp2[x]);
    }
    cout << sum ;
    return sum;
}   