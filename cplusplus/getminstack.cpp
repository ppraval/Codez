#include<bits/stdc++.h>
using namespace std;

stack<pair<int, int>> pushin(stack<pair<int, int>> s, int val)
{
    if(s.empty())
    {
        pair<int, int> p = {val, val};
        s.push(p);
    }
    else
    {
        pair<int, int> p = {val, min(val, s.top().second)};
        s.push(p);
    }
    return s;
}

stack<pair<int, int>> popout(stack<pair<int, int>> s)
{
    s.pop();
    return s;
}

void getMin(stack<pair<int, int>> s)
{
    pair<int, int> p = s.top();
    cout << p.second << endl;
}

int main()
{
    stack<pair<int, int>> s;
    s = pushin(s, 2);
    s = pushin(s, 3);
    s = pushin(s, 4);
    s = pushin(s, 1);
    s = pushin(s, 5);
    getMin(s);
    s = popout(s);
    s = popout(s);
    s = popout(s);
    getMin(s);
    return 0;
}