#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> res = {{4,8},{3,6},{10,20},{15,30}};
    double x;
    long long sum = 0;
    unordered_map<double, int> mp;
    for(int i = 0; i < res.size(); i++)
    {  
        x = (double)res[i][0] / res[i][1];
        if(mp.find(x) != mp.end())
            sum += mp[x]; 
        mp[x]++;
    }
    cout << sum << endl;
    return 0;
}