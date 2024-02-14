#include<bits/stdc++.h>
using namespace std;


int main()
{
    vector<vector<int>> grid =  {{0,1,1}, {1,0,1}, {0,0,1}};
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> ans(n, vector<int>(m, 0));
    vector<pair<int, int>> row_count(n, pair<int, int>(0, 0));
    vector<pair<int, int>> col_count(m, pair<int, int>(0, 0));

    for (int i = 0; i < n; i++) 
    {
        
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0)
                row_count[i].first++;
            else
                row_count[i].second++;
        }
    }

    for (int j = 0; j < m; j++) 
    {
        for (int i = 0; i < n; i++) 
        {
            if (grid[i][j] == 0)
                col_count[j].first++;
            else
                col_count[j].second++;
        }
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            ans[i][j] = row_count[i].second + col_count[j].second - (row_count[i].first + col_count[j].first);
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0; 
}