#include<bits/stdc++.h>
using namespace std;

bool sorting(const pair<int, int> a, const pair<int, int> b)
{
    return (double) a.first / (double) a.second > (double) b.first / (double) b.second;
}

int main()
{
    int n = 3;
    int w = 50;
    vector<int> val = {100, 60, 120};
    vector<int> wei = {20,10,30};
    vector<pair<int, int>> v (n);
    for(int i = 0; i < n; i++)
    {
        v[i].first = val[i];
        v[i].second = wei[i];
    }
    sort(v.begin(), v.end(), sorting);
    int curr = 0;
    double ans = 0.0;
    for(auto x : v)
    {
        if(curr + x.second <= w)
        {
            curr += x.second;
            ans += x.first;
        }
        else
        {
            int excess = w - x.second;
            ans += (x.first / (double) x.second ) * (double) excess;
            break;
        } 
    }
    cout << ans;
    return 0;
}