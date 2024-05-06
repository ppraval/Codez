#include<bits/stdc++.h>
using namespace std;

void printPoints(std::vector<std::vector<int>> &points)
{
    for (int i = 0; i < points.size(); i++)
    {
        for (int j = 0; j < points[i].size(); j++)
        {   
            cout << points[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> points = {{1,1},{2,2},{3,3}};
    // sort(points.begin(), points.end());
    // printPoints(points);
    int n = points.size();
    if(n < 3)
        return n;
    int ans = 2;
    double slope;
    for(int i = 0; i < n - 1; i++)
    {
        unordered_map<double, int> mp;
        for(int j = i + 1; j < n; j++)
        {
            int x1 = points[j][0], x2 = points[i][0];
            int y1 = points[j][1], y2 = points[i][1];

            if(x1 == x2)
            {
                slope = INT_MAX;
            }
            else
            {
                slope = 1.0 * (y2 - y1) / (x2 - x1);
            }
            mp[slope]++;
        }
        ans = max(ans, mp[slope] + 1);
    }
    cout << ans << endl;
    return 0;
}

