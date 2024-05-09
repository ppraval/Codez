#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "NES";
    int x = 0, y = 0;
    set<vector<int>> mp;
    mp.insert({0, 0});
    for(auto i : s)
    {
        if(i == 'N')
        {
            y++;
        }
        else if(i == 'S')
        {
            y--;
        }
        else if(i == 'E')
        {
            x++;
        }
        else if(i == 'W')
        {
            x--;
        }
        if(mp.find({x, y}) != mp.end())
        {
            cout << true;
            return true;
        }
        mp.insert({x, y});
    }
    cout << false;
    return false;
}