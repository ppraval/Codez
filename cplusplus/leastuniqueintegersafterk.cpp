#include<bits/stdc++.h>
using namespace std;

int  main()
{
    vector<int> arr = {5, 5, 4};
    int k = 1;
    unordered_map<int, int> mp;
    for(auto a : arr)
        mp[a]++;
    
    vector<int> v;
    int count = 0;
    for(auto a : mp)
    {
        v.push_back(a.second);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
    {
        if(k > v[i])
        {
            k -= v[i];
            v[i]=0;
        }
        else
        {
            v[i] -= k;
            k =0;
        }
        if(v[i]!=0)
            count++;
    }
    cout << count << endl;
    return count;
}