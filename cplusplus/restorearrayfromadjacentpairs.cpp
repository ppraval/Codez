#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> adjacentPairs = {{2, 1}, {3, 4}, {3, 2}};
    sort(adjacentPairs.begin(), adjacentPairs.end());
    for(int i = 0; i < adjacentPairs.size(); i++)
    {
        for(int j = 0; j < adjacentPairs[i].size(); j++)
        {
            cout << adjacentPairs[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}