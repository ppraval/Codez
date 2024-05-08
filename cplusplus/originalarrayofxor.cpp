#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> pref = {5,2,0,3,1};
    int n = pref.size();
    vector<int> ans(n);
    int xor_num = pref[0];
    ans[0] = pref[0];
    for(int i = 1; i < n; i++)
    {
        ans[i] = xor_num ^ pref[i];
        xor_num = pref[i];
    }
    for(int i : ans)
        cout << i << " ";
    return 0;
}