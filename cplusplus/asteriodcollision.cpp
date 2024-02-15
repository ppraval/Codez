#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> asteroids = {5, 10, -2};
    stack<int> s;
    vector<int> ans;
    for(int i = 0; i < asteroids.size() + 1; i++)
    {
        if(i == 0)
        {
            s.push(asteroids[i]);
        }
        if(asteroids[i] > s.top())
        {
            ans.push_back(s.top());
            s.push(asteroids[i]);
        }
    }
    for(int x : ans)
        cout << x << " ";
    return 0;
}