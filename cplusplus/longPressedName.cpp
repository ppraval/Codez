#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "alex";
    string t = "aaleex";
    int i = 0, j = 0;
    while (j < t.size()) 
    {
        if (i < s.size() && s[i] == t[j]) 
        {
            i++;
            j++;
        } 
        else if (j > 0 && t[j] == t[j - 1]) 
        {
            j++;
        } 
        else 
        {
            cout << "false";
            return false;
        }
    }
    if(i == s.size())
        cout << "true";
    else    
        cout << "false";
    return i == s.size();
}