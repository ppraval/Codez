#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, count = 0;
    string s = "";
    cin >> t;
    while(t > 0)
    {
        string temp;
        cin >> temp;
        s += temp;
        t--;
    }
    for(int i = 0; i + 1 < s.length(); i++)
    {
        if(s[i] == s[i + 1])
            count++;
    }
    cout << count + 1;
    return 0;
}