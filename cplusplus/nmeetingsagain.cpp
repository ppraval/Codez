#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 6;
    vector<int> s = {1,3,0,5,8,5};
    vector<int> e = {2,4,6,7,9,9};
    vector<int> ans;
    ans.push_back(1);
    int last_end = e[0];
    for(int i = 1; i < n; i++)
    {
        if(s[i] > last_end)
        {
            last_end = e[i];
            ans.push_back(i + 1);
        }
    }
    for(int i : ans)
        cout << i << " ";
    return 0;
}