#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> c = {1,2,2};
    vector<int> u = {1,2,3};
    int b = 4;
    unordered_map<int, int> mp;
    for(int i = 0; i < c.size(); i++)
        mp[c[i]] = u[i];
    int i = 0, j = c.size() - 1;
    int max_val = INT_MIN;
    sort(c.begin(), c.end());
    while(i < j)
    {
        int sum = c[i] + u[j];
        if(sum <= b)
        {
            max_val = max(max_val, mp[c[i]] + mp[c[j]]);
            i++;
        }
        else
        {
            j--;
        }
    }
    if(max_val != INT_MIN)
        cout << max_val;
    else
        cout << -1;
    return 0;
}