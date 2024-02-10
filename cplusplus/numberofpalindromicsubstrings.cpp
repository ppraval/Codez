#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "babab";
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        string str;
        int count = 0;
        int l = i, r = i;
        while(l >= 0 && r < n && s[l] == s[r])
        {
            str = s.substr(l, r - l + 1);
            cout << str << endl; 
            count++;
            l--;
            r++;
        }
        ans += count;

        l = i, r = i + 1, count = 0;
        while(l >= 0 && r < n && s[l] == s[r])
        {
            str = s.substr(l, r - l + 1);
            cout << str << endl; 
            count++;
            l--;
            r++;
        }
        ans += count;
    }
    cout << ans;
    return 0;
}