#include<bits/stdc++.h>
using namespace std;

void permu(int idx, vector<vector<int>> &ans, vector<int> v)
{
    if(idx == v.size())
    {
        ans.push_back(v);
        return;
    }
    for(int i = idx;i < v.size();i++)
    {
        swap(v[i], v[idx]);
        permu(idx+1, ans, v);
        swap(v[i], v[idx]);
    }
}

int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;
    permu(0, ans, nums);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << "( ";
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << ") ";
    }
    return 0;
}