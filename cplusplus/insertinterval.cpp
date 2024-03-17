#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2, 5};
    vector<vector<int>> ans;
    int start = newInterval[0], end = newInterval[1];
    bool flag = 0;
    for(int i = 0; i < intervals.size(); i++)
    {
        int curr_start = intervals[i][0];
        int curr_end = intervals[i][1];

        if(curr_end < start || flag == 1)
        {
            ans.push_back({curr_start, curr_end});
            continue;
        }
        start = min(start, curr_start);
        if(end < curr_start)
        {
            ans.push_back({start, end});
            ans.push_back({curr_start, curr_end});
            flag = 1;
            continue;
        }
        if(end <= curr_end)
        {
            ans.push_back({start, curr_end});
            flag = 1;
        }
    }
    if(flag == 0)
    {
        ans.push_back({start, end});
    }
    for(int i = 0; i < ans.size(); i++)
    {
        cout << "[" << ans[i][0] << ", " << ans[i][1] << "]" << " ";
    }
    return 0;
}