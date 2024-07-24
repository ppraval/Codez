#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> m, int i, int j, int &min_val, int steps, vector<vector<int>> &s)
{
    if(i < 0 || j < 0 || j > m[0].size() || i > m.size() || m[i][j] == 1 || s[i][j] == 1)
        return;
    if(i == 0 || j == 0 || i == m.size() - 1 || j == m[0].size() - 1)
    {
        min_val = min(min_val, steps);
        return;
    }
    s[i][j] = 1;
    dfs(m, i - 1, j, min_val, steps + 1, s);
    dfs(m, i + 1, j, min_val, steps + 1, s);
    dfs(m, i, j - 1, min_val, steps + 1, s);
    dfs(m, i, j + 1, min_val, steps + 1, s);
}

int main()
{
    vector<vector<int>> m = {
        {1,1,0,1},
        {0,0,0,1},
        {1,1,1,0},
    };
    int x = 1, y = 2;
    int min_val = INT_MAX;
    int steps = 0;
    vector<vector<int>> s(m.size(), vector<int> (m[0].size(), 0));
    dfs(m, x, y, min_val, steps, s);
    cout << min_val << endl;
    return 0;
}