#include<bits/stdc++.h>
using namespace std;

void subs(vector<int> nums, int i, vector<int> temp, vector<vector<int>> &ans)
{
    if(i >= nums.size())
    {
        ans.push_back(temp);
        return;
    }
    subs(nums, i + 1, temp, ans);
    temp.push_back(nums[i]);
    subs(nums, i + 1, temp, ans);
}

void stings(string s, int i, string temp_s, vector<string> &strs)
{
    if(i >= s.length())
    {
        strs.push_back(temp_s);
        return;
    }
    stings(s, i + 1, temp_s, strs);
    temp_s += s[i];
    stings(s, i + 1, temp_s, strs);
}

int main()
{
    vector<int> nums = {1,2,3,4};
    vector<vector<int>> ans;
    vector<int> temp;
    vector<string> strs;
    subs(nums, 0, temp, ans);
    for(auto x : ans)
    {
        for(int i : x)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    string s = "pain";
    string t = "";
    stings(s, 0, t, strs);
    for(auto x : strs)
    {
        cout << x << endl;
    }
    return 0;
}