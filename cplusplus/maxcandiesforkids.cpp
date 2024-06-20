#include<bits/stdc++.h>
using namespace std;

bool canAllot(vector<int>& v, int mid, long long k) 
{
    long long count = 0;
    for (int i = 0; i < v.size(); i++) 
    {
        count += v[i] / mid;
    }
    return count >= k;
}

int main()
{
    vector<int> v = {5,8,6};
    int k = 3;
    int low = 1;
    int high = *max_element(v.begin(),v.end());
    int ans = 0;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(canAllot(v, mid, k))
        {
            ans = mid;
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }
    cout << ans;
    return ans;
}