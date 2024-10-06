#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "bef";
    for(int i = 0; i < s.length(); i++)
    {
        string substr = "";
        for(int j = i; j < s.length(); j++)
        {
            substr += s[j];
            cout << substr << endl;
        }
    }
    return 0;
}