#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> s = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
    string temp;
    int ans = 0;
    for(auto x : s)
    {
        int count = 0;
        stringstream ss(x);
        while(ss >> temp)
        {
            cout << temp << endl;
            count++;
            ans = max(count, ans);
        }
    }
    cout << ans << endl;
    return ans;
}