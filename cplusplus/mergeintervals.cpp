#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    for(int i = 0; i < intervals.size(); i++)
    {
        if(intervals[i][0] <= ans.back()[1])
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        else
        {
            ans.push_back(intervals[i]);
        }
    }
    for(int i = 0; i < ans.size(); i++)
    {
        cout << "[" << ans[i][0] << ", " << ans[i][1] << "] ";
    }
    return 0;
}