#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        }); // This is a Lambda Function that sorts the elements in the array based on second element in the vector
    int current_end = points[0][1];
    int ans = 1;
    for(int i = 1; i < points.size(); i++)
    {
        if(points[i][0] > current_end)
        {
            ans++;
            current_end = points[i][1];
        }
    }
    cout << ans << endl;
    return 0;
}