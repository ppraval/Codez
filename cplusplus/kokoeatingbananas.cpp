#include<bits/stdc++.h>
using namespace std;

bool canEat(vector<int> p, int mid, int h)
{
    double time = 0.0;
    for(int i : p)
    {
        time += ceil((double)i / mid);
    }
    return time > h;
}

int main()
{
    vector<int> piles = {3,6,7,11};
    int h = 8;
    sort(piles.begin(), piles.end());
    int low = piles[0];
    int high = piles.back();
    int ans = -1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        // cout << "mid = " << mid << " low = " << low << " high = " << high << endl;
        if(canEat(piles, mid, h))
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    // cout << ans;
    return ans;
}