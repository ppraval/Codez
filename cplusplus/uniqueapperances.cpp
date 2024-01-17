#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {-3,0,1,-3,1,1,1,-3,10,0};
    vector<int> occ;
    unordered_map<int, int> ump;
    for(int i : arr)
    {
        ump[i]++;
    }
    for(auto x : ump)
    {
        occ.push_back(x.second);
    }
    vector<int> temp = occ;
    sort(temp.begin(), temp.end());
    auto new_end = unique(temp.begin(), temp.end());
    temp.erase(new_end, temp.end());
    if(temp.size() == occ.size())
    {
        cout << "true";
        return true;
    }
    cout << "false";
    return false;
}