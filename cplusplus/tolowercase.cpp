#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "Hello";
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] + 32;
        }
    }
    for(auto c : s)
        cout << c << " ";
    return 0;
}