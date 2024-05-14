#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> grid =  {{9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2}};
    int n = grid.size();
    vector<vector<int>> ans (n - 2, vector<int> (n - 2));
    for(int i = 1; i < n - 1; i++)
    {
        for(int j = 1; j < n - 1; j++)
        {
            int max_val = INT_MIN;
            for(int k = i - 1; k <= i + 1; k++)
            {
                for(int l = j - 1; l <= j + 1; l++)
                {
                    max_val = max(max_val, grid[k][l]);
                }
            }
            ans[i - 1][j - 1] = max_val;
        }
    }
    for(int i = 0; i < n - 2; i++)
    {
        for(int j = 0; j < n - 2; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
