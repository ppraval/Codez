#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> m = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    int tar = 3;
    int rows = m.size();
    int cols = m[0].size();
    int row = 0;
    int col = cols - 1;
    while(row < rows && col > -1)
    {
        int curr = m[row][col];
        if(curr == tar)
        {
            cout << "FOUND";
            return 0;
        }
        if(tar > curr)
        {
            row++;
        }
        else
        {
            col--;
        }
    }
    cout << "NOT FOUND";
    return 0;
}