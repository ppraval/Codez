#include<bits/stdc++.h>
using namespace std;

void sub(vector<pair<int, int>> c, int i, vector<pair<int, int>> temp, vector<vector<pair<int, int>>> &v)
{
    if(i >= c.size())
    {
        v.push_back(temp);
        return;
    }
    temp.push_back(c[i]);
    sub(c, i + 1, temp, v);
    temp.pop_back();
    sub(c, i + 1, temp, v);
}

int main()
{
    vector<int> c = {1,2,2};
    vector<int> u = {1,2,3};
    vector<pair<int, int>> pain, temp;
    vector<vector<pair<int, int>>> v;
    for(int i = 0; i < c.size(); i++)
    {
        pain.push_back({c[i], u[i]});
    }
    int b = 4;
    sub(pain, 0, temp, v);
    vector<vector<pair<int, int>>> store;
    for(auto x : v)
    {
        if(x.size() == 2)
        {
            store.push_back(x);
        }
    }
    int max_val = INT_MIN;
    for(int i = 0; i < store.size(); i++)
    {
        if(store[i][0].first + store[i][1].first <= b)
        {
            max_val = max(max_val, store[i][0].second + store[i][1].second);
        }
    }
    cout << max_val;
    return 0;
}