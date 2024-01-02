#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "egg";
    string t = "add";
    unordered_map<char, char> map;
    for(int i = 0; i < s.length(); i++)
    {
        if(map.find(s[i]) == map.end())
            map[s[i]] = t[i];
        else    
    }
    return 0;
}