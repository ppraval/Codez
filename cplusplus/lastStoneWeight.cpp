#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> s = {2,7,4,1,8,1};
    priority_queue<int> pq(s.begin(), s.end());
    while(pq.size() > 1)
    {
        int top = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        if(top != second)
        {
            pq.push(top - second);
        }
    }
    if(pq.empty())
    {
        cout << 0 << endl;
    }
    else
    {
        cout << pq.top() << endl;
    }
    return 0;
}