#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> r = {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};
    int n = 5;
    vector<int> degree(n, 0);
    for(auto x : r)
    {
        degree[x[1]]++;
        degree[x[0]]++;
    }
    vector<int> cities(n);
    for(int i = 0; i < n; i++)
    {
        cities[i] = i;
    }
    sort(cities.begin(), cities.end(), [&](int a, int b) 
    {
        return degree[a] > degree[b];
    });
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += (long long)(n - i) * degree[cities[i]];
    }
    cout << ans;
    return 0;
}