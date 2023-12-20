#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x = 10;
    if(x < 0)
    {
        cout << "false";
        return 0;
    }
    string temp = to_string(x);
    int i = 0;
    stack<char> s;
    while(i < temp.size())
    {
        s.push(temp[i]);
        i++;
    }
    string new_temp;
    new_temp.push_back(s.top());
    s.pop();
    while(!s.empty())
    {
        new_temp += s.top();
        s.pop();
    }
    if(temp == new_temp)
    {
        cout << "true";
        return true;
    }
    cout << "false";
    return false;
}

// the above code but condensed
// int main()
// {
//     int x = 10;
//     string str = to_string(n);
//     string s = str;
//     reverse(s.begin(),s.end());
//     return s == str;
// }