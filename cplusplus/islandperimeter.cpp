#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    int ans = 0;
    int n = grid.size();
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[i].size(); j++)
        {
            if(grid[i][j] == 1)
            {
                ans += 4;
                if(i != 0 && grid[i - 1][j] == 1)
                {
                    ans -= 2;
                }
                if(j != 0 && grid[i][j - 1] == 1)
                {
                    ans -= 2;
                }
                
            }
        }
    }
    cout << ans;
    return 0;
}