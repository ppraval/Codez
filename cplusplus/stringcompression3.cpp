#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcde";
    int n = s.length();
    int r = 0, l = 0;
    string ans = "";
    while(l < n)
    {
        int count = 0;
        while(s[r] == s[l] && count < 9)
        {
            l++;
            count++;
        }
        ans += to_string(count) + s[r];
        r = l;
    }
    cout << ans;
    return 0;
}