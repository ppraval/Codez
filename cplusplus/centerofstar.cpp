#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> edges = {{1,2},{2,3},{4,2}};
    int n = INT_MIN;
    for(auto i : edges)
    {
        n = max(n, max(i[0], i[1]));
    }
    auto matrix = vector<vector<int>>(n, vector<int>(n, 0));
    for(auto e : edges)
    {
        matrix[e[0] - 1][e[1] - 1] = 1;
        matrix[e[1] - 1][e[0] - 1] = 1;
    }
    bool flag = 1;    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j)
            {
                cout << matrix[i][j] << " ";
                if(matrix[i][j] == 0)
                {
                    flag = 0;
                } 
            }
        }
        cout << endl << flag << endl;
        if(flag)
        {
            cout << i + 1;
            return 0;
        }
        else
        {
            flag = 1;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}