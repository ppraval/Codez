#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = " the sky is  blue";
    string word, output;
    stringstream ss(s);
    stack<string> stack;
    while(ss >> word)
    {
        stack.push(word);
    }

    while(!stack.empty())
    {
        output += stack.top();
        if(stack.size() != 1)
        {
            output += " ";
        }
        stack.pop();
    }

    for(int i = 0; i < output.size(); i++)
    {
        cout << output[i];
    }

    return 0;
}