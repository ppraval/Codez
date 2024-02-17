#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcabcbb";
    int n = s.length();
    int max_length = 0;
    unordered_map<char, int> mp;
    int i = 0;
    for (int j = 0; j < n; j++) 
    {
        if (mp.count(s[j]) == 0 || mp[s[j]] < i) 
        {
            mp[s[j]] = j;
            max_length = max(max_length, j - i + 1);
        } 
        else 
        {
            i = mp[s[j]] + 1;
            mp[s[j]] = j;
        }
    }
    cout << max_length << endl;
    return max_length;
}