#include<bits/stdc++.h>
using namespace std;

int main()
{
    string t = "(abcd)";
    int n = t.length();
    string out = "";
    stack<int> s;

    for(int i = 0; i < n; i++)
    {
        if(t[i] == '(') 
            s.push(i);
        else if(t[i] == ')')
        {
            reverse(t.begin() + s.top() + 1, t.begin() + i);
            s.pop();
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(t[i] != '(' && t[i] != ')') 
        {
            out = out + t[i];
        }
    }
    cout << out << endl;
    return 0;
}