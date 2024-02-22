#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3;
    vector<vector<int>> trust = {{1,3}, {2,3}, {3,1}};
    vector<int>arr1(n+1);
    vector<int>arr2(n+1);
    for(int i = 0; i < trust.size(); i++)
    {
        arr1[trust[i][0]]++;   
        arr2[trust[i][1]]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(arr1[i] == 0 && arr2[i] == n-1)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}