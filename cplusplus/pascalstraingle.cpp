#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> main()
{
    int n = 5;
    vector<vector<int>> triangle;
    if (n == 0) return triangle;

    triangle.push_back({1});

    for (int i = 1; i < n; ++i) {
        vector<int> prev_row = triangle.back();
        vector<int> new_row = {1};

        for (int j = 1; j < prev_row.size(); ++j) {
            new_row.push_back(prev_row[j-1] + prev_row[j]);
        }

        new_row.push_back(1);
        triangle.push_back(new_row);
    }

    return triangle;
}