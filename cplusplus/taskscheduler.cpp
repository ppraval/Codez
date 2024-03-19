#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    int size = tasks.size();
    unordered_map<char, int> mp;
    for(auto a : tasks)
    {
        mp[a]++;
    }
    priority_queue<int> pq;
    for(auto x : mp) 
    {
        pq.push(x.second);
    }
    queue<pair<int, int>> q;
    int time = 0;
    while(!pq.empty() || !q.empty()) 
    {
        time++;
        if(pq.size() > 0) 
        {
            int curr = pq.top();
            pq.pop();
            int count = curr - 1;
            if(count > 0) 
            {
                q.push({count,time+n});
            }
        }

        if(!q.empty() && q.front().second == time) 
        {
            pq.push(q.front().first);
            q.pop();
        }
    }
    cout << time << endl;
    return time;
}