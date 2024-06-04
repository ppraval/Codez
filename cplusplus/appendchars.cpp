#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "coaching";
    string t = "coding";
    int i = 0, j = 0;
    int s1 = s.length();
    int t1 = t.length();
    while(i < s1 && j < t1)
    {
        if(s[i] == t[j])
        {
            j++;
        }
        i++;

    }
    cout << t1 - j << endl;
    return t1 - j;
}