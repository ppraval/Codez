#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i = 0; i < m; i++)
    {
        for(int j = 0;j < i; j++)
        {
            int x = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = x;
        }
    }
    for(int i = 0;i < m;i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }    

    return 0;
}