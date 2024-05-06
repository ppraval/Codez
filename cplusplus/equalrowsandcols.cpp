#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> grid = {{3,2,1},{1,7,6},{2,7,7}};
    int count = 0;
    for(int i = 0; i < grid.size(); i++)
    {
        vector<int> cols;
        for(int j = 0; j < grid.size(); j++)
        {
            cols.push_back(grid[j][i]);
        }
        for(int k = 0; k < grid.size(); k++)
        {
            vector<int> v = grid[k];
            if(v == cols)
            {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}