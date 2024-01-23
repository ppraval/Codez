#include<bits/stdc++.h>
using namespace std;


void solve(int n, int k, int i, vector<vector<int>>& ans, vector<int> output)
{
    if(i > n)
    {
        if(output.size() == k)
        {
            ans.push_back(output);
        }
        return;
    }
    if(output.size() == k)
    {
        return;
    }
    output.push_back(i);
    for(int j = i + 1; j <= n + 1; j++)
    {
        solve(n, k, j, ans, output);
    }
    output.pop_back();
}


int main()
{
    vector<vector<int>> ans;
    vector<int> comb;
    int n = 4;
    int k = 2;
    int i = 1;
    for(i = 1; i <= n; i++)
    {
        solve(n, k, i, ans, comb);
    }
    for(int i = 0; i < ans.size(); i++)
    {
        cout << "( ";
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << ") ";
    }
    return 0;
}