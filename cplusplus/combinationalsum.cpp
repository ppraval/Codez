#include<bits/stdc++.h>
using namespace std;

void subsets(vector<int> can, vector<int> temp, vector<vector<int>> &ans, int i, int n, int tar, int sum)
{
    if(sum == tar)
    {
        ans.push_back(temp);
        return;
    }
    if(sum > tar || i >= n)
    {
        return;
    }
    temp.push_back(can[i]);
    subsets(can, temp, ans, i, n, tar, sum + can[i]);
    temp.pop_back();
    subsets(can, temp, ans, i + 1, n, tar, sum);
}

int main()
{
    vector<int> can = {2,3,6,7};
    int tar = 7;
    vector<vector<int>> ans;
    vector<int> temp;
    subsets(can, temp, ans, 0, can.size(), tar, 0);
    for(auto x : ans)
    {
        for(int i : x)
            cout << i << " ";
        cout << endl; 
    }
    return 0;
}