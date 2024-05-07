#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<char>> grid = {{'B', 'W', 'B'}, {'B', 'W', 'W'}, {'B', 'W', 'B'}};
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2;  j++)
        {
            int b = 0, w = 0;
            if(grid[i][j] == 'B')
                b++;
            else
                w++;
            
            if(grid[i + 1][j] == 'B')
                b++;
            else
                w++;
            
            if(grid[i][j + 1] == 'B')
                b++;
            else
                w++;
            
            if(grid[i + 1][j + 1] == 'B')
                b++;
            else
                w++;
            if(w >= 3 || b >= 3)
            {
                return true;
            }
        }
    }
    return false;
}