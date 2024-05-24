#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "23";
    vector<string> ans;
    vector<string> mp = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    ans.push_back("");
    for(char ch : s)
    {
        vector<string> temp_ans;
        for(string s1 : ans)
        {
            for(char ch1 : mp[ch - '2'])
            {
                temp_ans.push_back(s1 + ch1);
            }
        }
        ans = temp_ans;
    }
    for(auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}