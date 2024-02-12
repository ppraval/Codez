#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "cbbd";
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int count = 0;
        int l = i, r = i;
        while(l >= 0 && r < n && s[l] == s[r])
        {
            count++;
            l--;
            r++;
        }
        ans += count;

        l = i, r = i + 1, count = 0;
        while(l >= 0 && r < n && s[l] == s[r])
        {
            count++;
            l--;
            r++;
        }
        ans += count;
    }
    cout << ans << endl;
    return 0;
}