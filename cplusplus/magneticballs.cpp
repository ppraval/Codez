#include<bits/stdc++.h>
using namespace std;

bool canPlace(vector<int> pos, int val, int m)
{
    int count = 1;
    int curr_placed = pos[0];
    for(int i = 1; i < pos.size(); i++)
    {
        if(pos[i] - curr_placed >= val)
        {
            count++;
            curr_placed = pos[i];
        }
        if(count >= m)
        {
            return true;
        }
    }
    return false;
}


int main()
{
    vector<int> pos = {1,2,3,4,7};
    int m = 3;
    sort(pos.begin(), pos.end());
    int low = 1;
    int high = (pos.back() - pos[0]) / (m - 1);
    int ans = 1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(canPlace(pos, mid, m))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return ans;
}