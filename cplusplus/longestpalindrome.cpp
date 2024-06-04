#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abccccdd";
    int count = 0;
    unordered_map<char, int> mp;
    for(char c : s)
    {
        mp[c]++;
    }
    for(auto x : mp)
    {
        if(x.second == 1 || x.second % 2 == 0)
        {
            count += x.second;
        }
    }
    cout << count;
    return count;
}