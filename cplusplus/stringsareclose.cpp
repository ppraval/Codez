#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abc";
    string t = "bca";
    vector<int> freq_s (26, 0);
    vector<int> freq_t (26, 0);
    for(char ch : s)
        freq_s[ch - 'a']++:
    for(char ch : t)
        freq_t[ch - 'a']++:
    sort(freq_s.begin(), freq_s.end());
    sort(freq_t.begin(), freq_t.end());
    for(int i = 0; i < 26; i++)
    {
        if(freq_s[i] != freq_t[i])
        {
            return false;
        }
    }
    return true;
}