#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "meenakshi";
    unordered_set<string> set;
    for(int i = 0; i < s.length(); i++)
    {
        string temp;
        for(int j = i; j < s.length(); j++)
        {
            temp += s[j];
            set.insert(temp);
        }
    }
    for(auto x : set)
        cout << x << endl;
    return 0;
}