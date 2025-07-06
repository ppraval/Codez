#include<bits/stdc++.h>
using namespace std;

int main()
{
    // vector<string> w = {"lc","cl","gg"};
    // vector<string> w = {"ab","ty","yt","lc","cl","ab"};
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    vector<string> w = {"cc","ll","xx"};
    unordered_map<string, int> mp;
    int count = 0;
    for (const string& str : w)
        mp[str]++;
    for(auto it : mp)
        cout << it.first << " " << it.second << endl;
    for (const string& str : w) 
    {
        string rev = str;
        reverse(rev.begin(), rev.end());
        if(rev == str)
            continue;
        if (mp.find(rev) != mp.end()) 
        {
            count += 4;
            mp.erase(rev);
            mp.erase(str);
        }
        for(auto it : mp)
            cout << it.first << " " << it.second << endl;
        cout << endl;
    }
    for(auto it : mp)
        cout << it.first << " " << it.second << endl;
    cout << mp.size() << endl;
    for(auto it : mp)
    {
        string rev = it.first;
        reverse(rev.begin(), rev.end());
        if(it.first == rev && it.second > 0)
        {
            count += 2 * it.second;
            break;
        }
    }
    cout << count << endl;
    return 0;
}