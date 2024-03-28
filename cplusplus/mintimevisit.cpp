#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> points = {{1, 1}, {3, 4}, {-1, 0}};
    int n = points.size();
    int result = 0;
    for(int i = 1; i < n; i++)
    {
        result += max(abs(points[i][0] - points[i-1][0]), abs(points[i][1]- points[i-1][1]));
    }
    cout << result << endl;
    return result;
}