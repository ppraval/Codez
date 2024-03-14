#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> cost = {10, 15, 20};
    int n = cost.size();
    for(int i = 2; i < n; i++)
    {
        cost[i] += min(cost[i - 1], cost[i - 2]);
    }
    cout << min(cost[n - 1], cost[n - 2]);
    return min(cost[n - 1], cost[n - 2]);
}