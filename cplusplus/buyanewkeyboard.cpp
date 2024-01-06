#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "poiinter";
    string res = "";
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] != 'i')
            res += s[i];
        if(s[i] == 'i')
        {
            reverse(res.begin(), res.end());
        }
    }
    cout << res << endl;
    return 0;
}