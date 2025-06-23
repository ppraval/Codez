#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcabc";
    vector<int> mp(3, 0);
    int left = 0;
    int res = 0;
    for(int i = 0; i < s.length(); i++)
    {
        mp[s[i] - 'a']++;
        while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0)
        {
            res += s.length() - i;
            mp[s[left] - 'a']--;
            left++;
        }
    }
    cout << res << endl;
    return 0;
}