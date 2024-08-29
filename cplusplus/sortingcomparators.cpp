#include<bits/stdc++.h>
using namespace std;

bool sorting(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

int main()
{
    vector<vector<int>> v = {{1,2}, {5,6}, {7,4}};
    sort(begin(v), end(v), sorting);
    for(auto x : v)
    {
        for(int i : x)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}