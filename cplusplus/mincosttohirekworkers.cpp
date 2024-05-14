#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> q = {10,20,5};
    vector<int> w = {70,50,30};
    int k = 2;
    double sum = 0, ans = INT_MAX;
    vector<pair<double, int>> v;
    for(int i = 0; i < q.size(); i++)
    {
        v.push_back({w[i]/(double)q[i], q[i]});
    }
    sort(v.begin(), v.end());
    priority_queue<int> pq;
    for(int i = 0; i < q.size(); i++)
    {
        pq.push(v[i].second);
        sum += v[i].second;
        if(pq.size() > k)
        {
            sum -= pq.top();
            pq.pop();
        }
        if(pq.size() == k)
        {
            ans = min(ans, sum * v[i].first);
        }
    }
    cout << ans;
    return ans;
}