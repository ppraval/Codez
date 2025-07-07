#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcyy";
    // string s = "azbk";
    int t = 2;
    unordered_map<char, int> mp;
    for (char c : s) {
        mp[c]++;
    }
    for(auto i : mp)
    {
        if(i.first == 'z')
        {
            mp['a']++;
            mp['b']++;
            mp.erase('z');
        }
    }
    cout << mp.size() << endl;
    return 0;
}