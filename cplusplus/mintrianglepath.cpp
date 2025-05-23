#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int n = triangle.size();
    for(int i = n - 2; i >= 0; i--)
    {
        for(int j = 0; j <= i; j++)
        {
            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    cout << triangle[0][0];
    return triangle[0][0];
}