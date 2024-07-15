#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>> &g, int i, int j, int val, int kolar)
{
    if(i < 0 || i >= g.size() || j < 0 || j >= g[0].size() || g[i][j] == kolar || g[i][j] != val)
    {
        return;
    }
    g[i][j] = kolar;
    dfs(g, i - 1, j, val, kolar);
    dfs(g, i + 1, j, val, kolar);
    dfs(g, i, j - 1, val, kolar);
    dfs(g, i, j + 1, val, kolar);
}


int main()
{
    vector<vector<int>> g = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, c = 2;
    int val = g[sr][sc];
    dfs(g, sr, sc, val, c);
    for(auto x : g)
    {
        for(int i : x)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}