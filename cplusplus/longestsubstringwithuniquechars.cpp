#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcabcbb";
    unordered_map<char, int> mp;
    int max_len = 1;
    int j = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(mp.find(s[i]) == 0 || mp[s[i]] < j)
        {
            mp[s[i]] = i;
            max_len = max(max_len, i - j + 1);
        }
        else
        {
            j = mp[s[i]] + 1;
            mp[s[i]] = i;
        }
    }
    cout << max_len;
    return 0;
}