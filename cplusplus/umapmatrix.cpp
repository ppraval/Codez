#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,3,4,1,2,3,1};
    unordered_map<int, int> umap;
    int count = 0;
    for(auto i : nums)
    {
        umap[i]++;
        count = max(count, umap[i]);
    }
    vector<vector<int>> res(count);
    for(auto i : umap)
    {
        for(int j = 0; j < i.second; j++)
        {
            res[j].push_back(i.first);
        }
    }
    for(int i = 0; i <res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}