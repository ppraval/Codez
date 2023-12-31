#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    int min_price = prices[0];
    int maxprof = 0;
    for(int i = 1; i < prices.size(); i++)
    {
        maxprof = max(maxprof, prices[i] - min_price);
        min_price = min(prices[i], min_price);
    }
    cout << maxprof;
    return maxprof;
}