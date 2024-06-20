#include<bits/stdc++.h>
using namespace std;

bool canFill(vector<int> weights, int cap, int max_days)
{
    int load = 0;
    int days = 1;
    for(int i : weights)
    {
        if(load + i > cap)
        {
            days++;
            load = i;
        }
        else
        {
            load += i;
        }
    }
    return days <= max_days;
}


int main()
{
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    // sort(weights.begin(), weights.end());
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        cout << "mid = " << mid << " low = " << low << " high = " << high << endl;
        if(canFill(weights, mid, days))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << low << endl;
    return low;
}