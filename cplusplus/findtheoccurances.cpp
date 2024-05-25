#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,3,1,7};
    vector<int> queries = {1,3,2,4};
    int x = 1;
    unordered_map<int, vector<int>> occurrences;
    vector<int> answers;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == x) {
            occurrences[x].push_back(i);
        }
    }
    for (int query : queries) 
    {
        if (query <= occurrences[x].size()) 
        {
            answers.push_back(occurrences[x][query - 1]);
        } 
        else 
        {
            answers.push_back(-1);
        }
    }
    for(int i : answers)
        cout << i << " ";
    return 0;
}