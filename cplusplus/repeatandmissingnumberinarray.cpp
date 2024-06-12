#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> A = {3,1,2,5,3};
    unordered_map<int, int> mp;
    vector<int> ans(2);
    for(int i : A)
        mp[i]++;
    for(int i = 1; i <= A.size(); i++)
    {
        if(mp.find(i) == mp.end())
        {
            ans[1] = i;
        }
        if(mp[i] == 2)
        {
            ans[0] = i;
        }
    }
    cout << ans[0] << " " <<  ans[1];
    return 0;
}