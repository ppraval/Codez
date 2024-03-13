#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, int> mp({{0, 1}});
    for(auto i : mp)
    {
        cout << i.first << i.second << endl;
    }
    return 0;
}