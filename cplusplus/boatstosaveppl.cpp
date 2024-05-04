#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {3,2,2,1};
    int lim = 3;
    sort(v.begin(), v.end());
    int sum = 0, ans = 0;
    int l = 0, r = v.size() - 1;
    while(l < r)
    {
        sum = v[r] + v[l];
        if(sum <= lim)
        {
            ans++;
            l++;
            r--;   
        }
        else
        {
            ans++;
            r--;
        }
    }
    if(l == r)
        ans++;
    cout << ans;
    return 0;
}