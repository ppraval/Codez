#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abc";
    int ans = s.length();
    char a = 'a';
    for(auto c : s) 
    {
        int cw = 26 - abs(c - a);
        int acw = abs(c - a);
        ans += min(cw, acw);
        a = c;
    }
    cout << ans << endl;
    return 0;
}