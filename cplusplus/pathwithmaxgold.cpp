#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> grid, int x, int y, int n, int m, vector<int> row_vec, vector<int> col_vec)
{
    if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0)
    {
        return 0;
    } 
    int curr_gold = grid[x][y];
    grid[x][y] = 0;
    int max_path_gold = curr_gold;
    for(int i = 0; i < 4; i++)
    {
        int x1 = x + row_vec[i];
        int y1 = y + col_vec[i];
        max_path_gold =  max(max_path_gold, curr_gold + dfs(grid, x1, y1, n, m, row_vec, col_vec));
    }
    grid[x][y] = curr_gold;
    return max_path_gold;
}


int main()
{
    vector<vector<int>> grid = {{0,6,0},{5,8,7},{0,9,0}};
    // vector<vector<int>> grid = {{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}};
    vector<int> row_vec = {1, -1, 0, 0};
    vector<int> col_vec = {0, 0, -1, 1};
    int max_gold = 0;
    int n = grid.size();
    int m = grid[0].size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] != 0)
            {
                max_gold = max(max_gold, dfs(grid, i, j, n, m, row_vec, col_vec));
            }
        }
    }
    cout << max_gold << endl;
    return max_gold;
}