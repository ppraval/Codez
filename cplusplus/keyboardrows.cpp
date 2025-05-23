#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> words = {"Hello","Alaska","Dad","Peace"};
    string s1="qwertyuiop";
    string s2="asdfghjkl";
    string s3="zxcvbnm";
    vector<string, int> res;
    map<char, int> mp;
    for(auto &it : s1)
    mp[it] = 1;
    for(auto &it : s2)
    mp[it] = 2;
    for(auto &it : s3)
    mp[it] = 3;
    for(auto &it : words)
    {
        int i;
        for( i = 1;i < it.size(); i++)
        {
            if(mp[tolower(it[i])] != mp[tolower(it[i - 1])])
            {
                break;
            }
        }
        if(i == it.size())
            res.push_back(it);
    }
    for(auto x : res)
        cout << x << " ";
    return 0;
}