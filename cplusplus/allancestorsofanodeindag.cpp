#include<bits/stdc++.h>
using namespace std;

void dfs(int parent, int v, vector<vector<int>>& adj_list, vector<vector<int>>& ans)
{
    for(int x : adj_list[v])
    {
        if(ans[x].empty() || ans[x].back() != parent)
        {
            ans[x].push_back(parent);
            dfs(parent, x, adj_list, ans);
        }
    }
}

int main()
{
    int n = 8;
    vector<vector<int>> edges = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};
    vector<vector<int>> ans(n), adj_list(n);
    for(auto &e : edges)
    {
        adj_list[e[0]].push_back(e[1]);
    }
    for(int i = 0; i < n; i++)
    {
        dfs(i, i, adj_list, ans);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}