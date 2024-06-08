#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "assc";
    stack<char> stk;
    stk.push(s[0]);
    string ans = "";
    int i = 1;
    while(i < s.length())
    {
        if(isdigit(s[i]))
        {
            stk.pop();
        }
        else
        {
            stk.push(s[i]);
        }
        i++;
    }
    while(!stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}