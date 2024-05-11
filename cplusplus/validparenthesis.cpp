#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "(*))";
    stack<int> brac, star;
    int n = s.length();
    for(int i = 0; i < n; i++) 
    {
        if(s[i] == '(')
        {
            brac.push(i);
        }
        else if(s[i] == '*')
        {
            star.push(i);
        }
        else 
        {
            if(!brac.empty())
                brac.pop();
            else if(!star.empty()) 
                star.pop();
            else
                return false;
        }
    }

    while(!brac.empty()) 
    {
        if(star.empty())
        {
            return false;
        }
        else if(brac.top() < star.top()) 
        {
            brac.pop();
            star.pop();
        }
        else
        {
            return false;
        }
    } 
    return true;
}