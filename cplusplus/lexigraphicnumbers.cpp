#include<bits/stdc++.h>
using namespace std;

void dfs(int val, int n, vector<int>& ans)
{
    if(val > n)
    {
        return;
    }
    ans.push_back(val);
    for(int i = 0; i <= 9; i++)
    {
        dfs(val * 10 + i, n, ans);
    }
}

int main()
{
    int n = 13;
    vector<int> ans;
    for(int i = 1; i <= 9; i++)
    {
        dfs(i, n, ans);
    }
    for(int i : ans)
        cout << i << " ";
    return 0;
}