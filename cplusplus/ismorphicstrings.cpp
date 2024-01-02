#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "badc";
    string t = "baba";
    unordered_map<char, char> map;
    for(int i = 0; i < s.length(); i++)
    {
        map[s[i]] = t[i];
    }
    for(auto i : map)
    {
        if(map.count(i.second) > 1)
        {
            cout << "false";
        }
    }
    // string res = "";
    // for(int i = 0; i < s.length(); i++)
    // {
    //     res.push_back(map[s[i]]);
    // }
    // if(res == t)
    //     cout << "true" << endl;
    // else
    //     cout << "false" << endl;
    return 0;
}