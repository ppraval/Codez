#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> tri = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};
    int n = tri.size();
    for(int i = n - 2; i >= 0; i--)
    {
        for(int j = n - 1; j >= 0; j--)
        {
            tri[i][j] += min(tri[i + 1][j], tri[i + 1][j + 1]);
        }
    }
    cout << tri[0][0];
    return 0;
}