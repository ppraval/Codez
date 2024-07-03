#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3;
    vector<int> start = {10,12,20};
    vector<int> end = {20,25,30};
    vector<int> ans;
    ans.push_back(1);
    int last_end = end[0];
    for(int i = 1; i < n; i++)
    {
        if(start[i] > last_end)
        {
            last_end = end[i];
            ans.push_back(i + 1);
        }
    }
    for(int i : ans)
        cout << i << " ";
    return 0;
}