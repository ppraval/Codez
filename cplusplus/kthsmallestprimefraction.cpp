#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,2,3,5};
    int k = 3;
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> q;
    int n = nums.size();
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            q.push({(double)nums[i] / nums[j], {nums[i], nums[j]}});
        }
    }
    pair<int, int> ans;
    while(k--)
    {
        ans = q.top().second;
        q.pop();
    }
    cout << ans.first << " " << ans.second;
    return 0;
}