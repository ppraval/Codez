#include<bits/stdc++.h>
using namespace std;

int main()
{
    string pattern = "abba";
    string s = "dog cat cat pain";
    unordered_map<char, string> mp1;
    unordered_map<string, char> mp2;
    vector<string> str;
    int n = s.length(), u = 0;
    for(int i = 0, j = 0; i <= n && j < n; i++)
    {
        if(s[i] == ' ' || i == n)
        {
            string s1 = s.substr(j, i - j);
            mp1[pattern[u++]] = s1;
            str.push_back(s1);
            j = i + 1;
        }
    }
    for(auto i : mp1)
    {
        cout <<  i.first << " " << i.second << endl;
        mp2[i.second] = i.first;
    }
    string res = "";

    for(auto c : str)
    {   
        res.push_back(mp2[c]);
    }
    cout << res <<endl;
    if(res == pattern)
    {
        cout << "true";
    }
    cout << "false";
    return 0;
}