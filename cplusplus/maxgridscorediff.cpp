#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> grid = {{9,5,7,3},{8,9,6,1},{6,7,14,3},{2,5,3,1}};
    int m = grid.size();
    int n = grid[0].size();
    int max_diff = -1e9;
    cout << max_diff << endl << endl;
    for(int i = m - 1; i >= 0; i--)
    {
        for(int j = n - 1; j >= 0; j--)
        {
            int curr_max = -1e9;
            if(i + 1 < m)
            {
                curr_max = max(curr_max, grid[i + 1][j]);
            }
            if(j + 1 < n)
            {
                curr_max = max(curr_max, grid[i][j + 1]);
            }
            max_diff = max(max_diff, curr_max - grid[i][j]);
            grid[i][j] = max(grid[i][j], curr_max);
        }
    }
    cout << max_diff;
    return max_diff;
}