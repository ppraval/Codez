#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "bab";
    string t = "aba";
    int ans = 0;
    unordered_map<char, int> mp;
    for(char c : s)
        mp[c]++;
    for(char c : t)
    {
        if(mp.find(c) == mp.end())
        {
            ans++;
        }
        else
        {
            mp[c]--;
            if(mp[c] == 0)
            {
                mp.erase(c);
            }
        }
    }
    cout << ans << endl;
    return ans;
}