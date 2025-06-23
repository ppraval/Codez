#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    map<int, vector<int>> mp;
    int n = matrix.size();
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < matrix[i].size(); j++) 
        {
            // cout << i + j << "\n";
            mp[i + j].push_back(matrix[i][j]);
        }
    }
    vector<int> res;
    for (const auto& pair : mp) 
    {
        // cout << "Diagonal " << pair.first << ": ";
        const vector<int>& diagonal = pair.second;
        for (int i = diagonal.size() - 1; i >=0 ; i--) 
        {
            res.push_back(diagonal[i]);
        }
    }
    for(int x : res)
    {
        cout << x << " ";
    }
    return 0;
}