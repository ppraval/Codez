#include<bits/stdc++.h>
using namespace std;

bool canRepair(vector<int> ranks, int cars, long long mid)
{
    long long repair_cars = 0;
    for(int i : ranks)
    {
        repair_cars += sqrt(mid / i);
    }
    return repair_cars >= cars;
}

int main()
{
    vector<int> ranks = {4,2,3,1};
    int cars = 10;
    sort(ranks.begin(), ranks.end());
    long long low = 1;
    long long high = LONG_MAX;
    long long mid, ans = LONG_MAX;
    while(low <= high)
    {
        mid = low + (high - low) / 2;
        if(canRepair(ranks, cars, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}