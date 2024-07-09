#include<bits/stdc++.h>
using namespace std;


void subsetSums(vector<int> arr, vector<int>& ans, int i, int sum, int n)
{
    if(i == n)
    {
        ans.push_back(sum);
        return;
    }
    subsetSums(arr, ans, i + 1, arr[i] + sum, n);
    subsetSums(arr, ans, i + 1, sum, n);
}


int main()
{
    vector<int> arr = {3,1,2};
    vector<int> ans;
    int n = 3;
    subsetSums(arr, ans, 0, 0, n);
    sort(ans.begin(), ans.end());
    for(int i : ans)
        cout << i << " ";
    return 0;
}