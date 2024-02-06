#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    unordered_map<string, int> mp;
    vector<vector<string>> ans; 
    for (int i = 0; i < strs.size(); i++) 
    {
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        if (mp.find(temp) != mp.end()) 
        {
            ans[mp[temp]].push_back(strs[i]);
        } 
        else 
        {
            mp[temp] = ans.size();
            ans.push_back({strs[i]});
            
        }
    }
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}