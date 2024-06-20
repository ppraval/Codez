#include<bits/stdc++.h>
using namespace std;

bool canArrive(vector<int> dist, double h, int mid)
{
    double time = 0;
    int i = 0;
    while(time <= h && i < dist.size() - 1)
    {
        time += ceil(static_cast<double>(dist[i]) / mid);
        i++;
    }
    time += static_cast<double>(dist[dist.size() - 1]) / mid;
    // cout << "For the value" << " " << mid << " We have canArrive = " << (time <= h) << endl;
    return (time <= h);
}

int main()
{
    vector<int> dist = {1,3,2};
    double h = 2.7;
    int n = dist.size(); 
    int ans = -1;
    if(h < n - 1)
        return ans;
    double upper = 0, lower = 0;
    for(int d : dist)
    {
        double curr = d * 1.0;
        lower += curr / h;
        upper += curr / (h - n + 1);
    }
    cout << lower << "  " << upper << endl;
    int low = floor(min(lower, 10e7));
    int high = ceil(min(upper, 10e7));
    int flag = 1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        cout << mid << endl;
        if(canArrive(dist, h, mid))
        {   
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans;
    return ans;
}