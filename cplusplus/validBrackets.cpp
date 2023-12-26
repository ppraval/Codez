#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "()";
    stack<char> stack;
    for(char c : s)
    {
        if(c == '(' || c == '{' || c == '[')
            stack.push(c);
        else
        {
            if(stack.empty() || (c == ')' && stack.top() != '(') || (c == '}' && stack.top() != '{') || (c == ']' && stack.top() != '['))
            {
                cout << "false" << endl;
                return false;
            }
            stack.pop();
        }
    }
    if(stack.empty())
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return stack.empty();
}