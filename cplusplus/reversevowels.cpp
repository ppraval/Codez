#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "hello";
    string v = "";
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            v += s[i];
        }
    }
    reverse(v.begin(), v.end());
    int j = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            s[i] = v[j++];
        }
    }
    cout << s << endl;
    return 0;
}