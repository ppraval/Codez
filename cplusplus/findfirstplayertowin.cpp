#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> s = {4,2,6,3,9};
    int k = 2;
    int n = s.size();
    deque<int> q;
    for(int i = 1; i < n; i++)
    {
        q.push_back(i);
    }
    int curr = 0, win = 0;
    while(1)
    {
        int top = q.front();
        q.pop_front();
        if(s[top] < s[curr])
        {
            win++;
            q.push_back(top);
        }
        else
        {
            win = 1;
            q.push_back(curr);
            curr = top;
        }
        if(win == k || win >= n - 1)
        {
            cout << curr;
            return curr;
        }
    }
    return 0;
}