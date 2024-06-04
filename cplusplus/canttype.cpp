#include<bits/stdc++.h>
using namespace std;

int main()
{
    string t = "hello world";
    string l = "ad";
    unordered_map<char, int> mp;
    for(char c : l)
    {
        mp[c]++;
    }
    stringstream ss(t);
    string word;
    int count = 0;
    bool flag = 0;
    while(ss >> word)
    {
        // cout << word << endl;
        for(char c : word)
        {
            if(mp.find(c) != 0)
            {
                // cout << c << endl;
                flag = 1;
            }
        }
        if(flag)
        {
            flag = 0;
            break;
        }
        count++;
    }
    // cout << count;
    return count;
}