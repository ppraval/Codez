#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> prices = {1, 2, 2};
    int money = 3;
    int n = prices.size();
    sort(prices.begin(), prices.end());
    int min_diff;
    if(prices[0] + prices[1] == money)
    {
        cout << 0 << " ";
        return 0;
    }
    else if(prices[0] + prices[1] > money)
    {
        cout << money << " ";
        return 0;
    }
    else
    {
        min_diff = abs(prices[1] + prices[0] - money);
    }
    int i = 0, j = n - 1;
    while (i < j)
    {
        int diff = abs(prices[j] + prices[i] - money);
        cout << "i = " << i << " j = " << j << "\n";
        if(diff < money)
        {
            i++;
        }
        if(diff > money)
        {
            j--;
        }
        min_diff = min(min_diff, diff);
        cout << "The diff is = " << diff << "\n";
    }
    cout << "The min difference is: " << min_diff;
    return 0;
}
