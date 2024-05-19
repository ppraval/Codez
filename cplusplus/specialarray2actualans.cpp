#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {3,4,1,2,6};
    vector<vector<int>> queries = {{0,2},{2,4}};
    vector<bool> ans;
    vector<int> temp;
    temp.push_back(0);
    int j = 0;
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] % 2 == nums[i - 1] % 2)
        {
            j++;
        }
        cout << j << endl;
        temp.push_back(j);
    }
    for(auto q : queries)
    {
        ans.push_back(temp[q[0]] == temp[q[1]]);
    }
    for(auto x : ans)
        cout << x << " ";
    return 0;
}