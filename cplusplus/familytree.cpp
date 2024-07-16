#include<bits/stdc++.h>
using namespace std;

int dfs(int v, vector<bool> &visited, vector<vector<int>> list)
{
    visited[v] = true;
    int max_h = 0;
    for(int u : list[v])
    {
        // cout << u << endl;
        if(!visited[u])
        {
            int h = dfs(u, visited, list);
            max_h = max(max_h, h);
        }
    }
    return max_h + 1;
}

int main()
{
    // int n = 4;
    // vector<pair<string, string>> g = { 
    //     {"John", "Alex"},
    //     {"Alex", "William"},
    //     {"William", "Rony"},
    //     {"William", "Rose"},
    // };
    int n = 6;
    vector<pair<string, string>> g = { 
        {"Ram", "Lava"},
        {"Darshrath", "Ram"},
        {"Darshrath", "Laxman"},
        {"Darshrath", "Shatrughan"},
        {"Ram", "Kusha"},
        {"Darshrath", "Bharat"}
    };
    unordered_set<string> s;
    int i = 0;
    for(auto x : g)
    {
        s.insert(x.first);
        s.insert(x.second);
    }
    int l = s.size();
    unordered_map<string, int> mp;
    for(auto x : s)
    {
        mp[x] = i++;
    }
    // for(auto x : mp)
    // {
    //     cout << x.first << "-" << x.second << endl;
    // }
    vector<vector<int>> list(l);
    for(auto x : g)
    {
        // cout << mp[x.first] << "~" << mp[x.second] << endl;
        list[mp[x.first]].push_back(mp[x.second]);
        list[mp[x.second]].push_back(mp[x.first]);
    }
    // for(auto x : list)
    // {
    //     for(int i : x)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    vector<bool> visited(l, false);
    int ans = dfs(0, visited, list);
    cout << endl << ans - 1 << endl;
    return 0;
}