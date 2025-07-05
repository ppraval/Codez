#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> dom = {{1,2},{2,1},{3,4},{5,6}};
    map<pair<int, int>, int> mp;
    int count = 0;
    for(auto& d : dom)
    {
        if(d[0] > d[1]) 
            swap(d[0], d[1]);
        count += mp[make_pair(d[0], d[1])]++;
    }
    cout << "Number of equivalent pairs: " << count << endl;
    return count;
}