#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcabcbb";
    unordered_map<char, int> mp;
    int max_len = 0;
    int j = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(mp.find(s[i]) == mp.end() || mp[s[i]] < j)
        {
            max_len = max(max_len, i - j + 1);
            mp[s[i]] = i;
        }
        else
        {
            j = mp[s[i]] + 1;
            mp[s[i]] = i;
        }
    }
    cout << max_len << endl;
    return 0;
}