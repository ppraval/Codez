#include<bits/stdc++.h>
using namespace std;

bool sorting(const vector<int> a, const vector<int> b)
{
    return a[2] > b[2];
}

int main()
{
    int n = 4;
    vector<vector<int>> v = {{1,4,20},{2,1,10},{3,1,40},{4,1,30}};
    sort(v.begin(), v.end(), sorting);
    int max_time = INT_MIN;
    for(auto x : v)
    {
        max_time = max(max_time, x[1]);
    }
    vector<int> time(max_time + 1, -1);
    int count = 0, profit = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = v[i][1]; j >= 0; j--)
        {
            if(time[j] == -1)
            {
                time[j] = i;
                count++;
                profit += v[i][2];
                break;
            }
        }
    }
    cout << count << " : " << profit;
    return 0;
}