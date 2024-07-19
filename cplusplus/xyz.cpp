#include<bits/stdc++.h>
using namespace std;

int rec(string s, string t, int i, int j)
{
    if(i < 0)
        return j + 1;
    if(j < 0)
        return i + 1;
    if(s[i] == t[j])
        return rec(s, t, i - 1, j - 1);
    return min({rec(s, t, i - 1, j), rec(s, t, i, j - 1), rec(s, t, i - 1, j - 1)}) + 1;
}

int main()
{
    string s = "horse";
    string t = "ros";
    int ans=f(s,t,s.size()-1,t.size()-1);
    cout<<ans<<endl;
    cout << rec(s, t, s.length() - 1, t.length() - 1);
    return 0;
}