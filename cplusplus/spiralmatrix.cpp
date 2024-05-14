#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
    int n = grid.size();
    int m = grid[0].size();
    vector<int> ans;
    int up = 0, down = n - 1, right = m - 1, left = 0;
    while(ans.size() < n * m)
    {
        for(int j = left; j <= right; j++)
        {
            ans.push_back(grid[up][j]);
        }
        up++;

        for(int i = up; i <= down; i++)
        {
            ans.push_back(grid[i][right]);
        }
        right--;

        if(up <= down)
        {
            for(int j = right; j >= left; j--)
            {
                ans.push_back(grid[down][j]);
            }
            down--;
        }
        if(left <= right)
        {
            for(int i = down; i >= up; i--)
            {
                ans.push_back(grid[i][left]);
            }
            left++;
        }
    }
    for(int i : ans)
        cout << i << " ";
    return 0;
}