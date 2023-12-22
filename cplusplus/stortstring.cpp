#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> strs = {"flower","flow","flight"};
    sort(strs.begin(), strs.end());
    int l = strs.size();
    int m = strs[0].size(); int n = strs[l - 1].size();
    string res = "";
    for(int i = 0; i < min(m, n); i++)
    {
        if (strs[0][i] == strs[l - 1][i])
            res.push_back(strs[0][i]);
        else
            break;
    }
    cout << res;
    return 0;
}