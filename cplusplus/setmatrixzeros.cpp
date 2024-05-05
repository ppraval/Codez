#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    unordered_set<int> rows;
    unordered_set<int> cols;
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            if(matrix[i][j] == 0)
            {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }

    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            if(rows.count(i) > 0 || cols.count(j) > 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}