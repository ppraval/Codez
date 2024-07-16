#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r = 3;
    int c = 2;
    vector<vector<int>> dir = {
        {4,3,5},
        {4,3,1},
        {1,6,5},
        {6,1,5},
        {6,1,3},
        {3,4,2}
    };
    int sum = 1;
    int start = 1;
    for(int i = 0; i < r; i++)
    {
        cout << "Starts in the loop = " << endl;
        for(int j = 0; j < c; j++)
        {
            cout << "Start = " << start << endl;
            if(i == 0 && j == 0)
            {
                start = dir[start - 1][0];
                continue;
            }
            if(i % 2 == 0)
            {
                sum += start;
                if(j != c - 1)
                    start = dir[start - 1][0];
            }
            else if(i % 2 == 1)
            {
                sum += start;
                if(j != c - 1)
                    start = dir[start - 1][1];
            }
        }
        cout << "Start before the flip = " <<  start << endl;
        start = dir[start - 1][2];
        cout << "Start after the loop and flip down " <<  start << endl;
        cout << endl;
    }
    cout << sum << endl;
    return 0;
}