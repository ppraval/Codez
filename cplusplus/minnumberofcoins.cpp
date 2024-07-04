#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v = 49;
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    vector<int> ans;
    int n = coins.size();
    for(int i = n - 1; i >= 0; i--)
    {
        while(v >= coins[i])
        {
            v -= coins[i];
            ans.push_back(coins[i]);
        }
    }
    for(int i : ans)
        cout << i << " ";
    return 0;
}