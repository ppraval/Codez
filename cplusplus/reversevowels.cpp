#include<bits/stdc++.h>
using namespace std;

bool isVowel(char ch)
{
    switch(ch)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default :
            return false;
    }
    
}


int main()
{
    string s = "hellow";
    int n = s.size();
    stack<char> stack;
    for(int i = 0; i < n; i++)
    {
        if(isVowel(s[i]))
        {
            stack.push(s[i]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(isVowel(s[i]))
        {
            s[i] = stack.top();
            stack.pop();
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << s[i];
    }
    return 0;
}