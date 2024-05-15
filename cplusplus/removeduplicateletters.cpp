#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "cbacdcbc";
    unordered_map<char, int> mp;
    stack<char> stk;
    vector<bool> inStack(26, false);
    for(char c : s)
        mp[c]++;
    for(char c : s)
    {
        mp[c]--;
        if(inStack[c - 'a'])
        {
            continue;
        }
        while (!stk.empty() && stk.top() > c && mp[stk.top()] > 0)
        {
            inStack[stk.top() - 'a'] = false;
            stk.pop();
        }
        stk.push(c);
        inStack[c - 'a'] = true;
    }
    string ans = "";
    while(!stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}