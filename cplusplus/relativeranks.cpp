#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> score = {10,3,8,9,4};
    pair<int, int> p;
    vector<string> ans(score.size());
    vector<pair<int, int>> v;
    for(int i = 0; i < score.size(); i++)
    {
        p.first = score[i];
        p.second = i;
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    for(int i = v.size() - 1; i >= 0; i--)
    {
        if(i == v.size() - 1)
            ans[v[i].second] = "Gold Medal";
        else if(i == v.size() - 2)
            ans[v[i].second] = "Silver Medal";
        else if(i == v.size() - 3)
            ans[v[i].second] = "Bronze Medal";
        else
            ans[v[i].second] = to_string(v.size() - i);
    }

    for(auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}