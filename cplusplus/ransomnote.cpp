#include<bits/stdc++.h>
using namespace std;

int main()
{
    string ransomNote = "aa";
    string magazine = "ab";
    unordered_map<char, int> mp;
    for(char c : magazine)
    {
        mp[c]++;
    }
    for(char c : ransomNote)
    {
        if(mp[c]-- == 0)
        {
            cout << "false";
            return false;
        }
        // cout << mp[c] << endl;
    }
    cout << "true";
    return true;
}