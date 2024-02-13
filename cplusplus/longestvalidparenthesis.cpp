#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = ")()())";
    stack<int> stck;

    stck.push(-1);
    int max_len = 0;

    for(int i = 0; i < s.length(); i++)
    {
        int j = stck.top();
        if(j != -1 && s[i] == ')' && s[j] == '(')
        {
            stck.pop();
            max_len = max(max_len, i - stck.top());
        }
        else
        {
            stck.push(i);
        }
    }
    cout << max_len << endl;
    return 0;
}