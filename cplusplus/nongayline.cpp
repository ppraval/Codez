#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> coordinates = {{0,0},{0,1},{0,-1}};
    float slope;
    if(coordinates[1][0] == 0 && coordinates[0][0] == 0)
            slope = coordinates[1][1] - coordinates[0][1];
        else
            slope = (coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);

    cout << "The slope is " << slope << endl;
    for(int i = 1; i + 1 < coordinates.size(); i++)
    {
            float new_slope;
            if(coordinates[i + 1][0] == 0 && coordinates[i][0] == 0)
                new_slope = coordinates[i + 1][1] - coordinates[i][1];
            else
                new_slope = (coordinates[i + 1][1] - coordinates[i][1]) / (coordinates[i + 1][0] - coordinates[i][0]);
            cout << "The new slope is " << new_slope << endl;
            if(new_slope != slope)
            {
                cout << false;
                return false;
            }
            slope = new_slope;
    }
    cout << true;
    return true;
}