#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> tokens = {"4","13","5","/","+"};
    stack<int> s;
    for(int i = 0; i < tokens.size(); i++)
    {
        if(tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "-" || tokens[i] == "+")
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            int res;
            if(tokens[i] == "-")
                res = a - b;
            if(tokens[i] == "+")
                res = a + b;
            if(tokens[i] == "*")
                res = a * b;
            if(tokens[i] == "/")
                res = a / b;
            s.push(res);
        }
        else
        {
            s.push(stoi(tokens[i]));
        }
    }
    cout << s.top() << endl;
    return 0;
}