#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abc";
    string t = "ahbgdy";
    int found = 0;
    for(int i = 0, j = 0; i < t.size(); i++)
    {
        if(t[i] == s[j])
        {
            found++;
            j++;
        }
    }
    if(found == s.size())
    {
        cout << "Found";
    }
    else
    {
        cout << "Not Found";
    }
    return 0;
}