#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r = 3;
    int c = 3;
    vector<vector<int>> m = {{1,3,5},{2,6,9},{3,6,9}};
    vector<int> arr;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            arr.push_back(m[i][j]);
        }
    }
    sort(arr.begin(), arr.end());
    cout << arr[arr.size() / 2];
    return 0;
}