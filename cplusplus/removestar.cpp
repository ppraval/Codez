#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "erase*****";
    string res = "";
    for(int i = 0; i < s.length(); i++)
    {
        res.push_back(s[i]);
         if(s[i] == '*')
         {
             res.pop_back();
             res.pop_back();
         }
    }
    cout << res;
    return 0;
}