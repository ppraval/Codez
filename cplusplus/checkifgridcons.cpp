#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> grid = {{1,0,2},{1,0,2}};
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (i < m - 1 && grid[i][j] != grid[i + 1][j]) 
            {
                return false;
            }
            if (j < n - 1 && grid[i][j] == grid[i][j + 1]) 
            {
                return false;
            }
        }
    }
    return true;
}