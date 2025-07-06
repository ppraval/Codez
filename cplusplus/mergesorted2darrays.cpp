#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> nums1 = {{1,2},{2,3},{4,5}};
    vector<vector<int>> nums2 = {{1,4},{3,2},{4,1}};
    vector<vector<int>> ans;
    int i = 0, j = 0; 
    while(i < nums1.size() && j < nums2.size())
    {
        if(nums1[i][0] == nums2[j][0])
        {
            ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
            i++;
            j++;
        }
        else if(nums1[i][0] < nums2[j][0])
        {
            ans.push_back(nums1[i]);
            i++;
        }
        else
        {
            ans.push_back(nums2[j]);
            j++;
        }
    }
    while(i < nums1.size())
    {
        ans.push_back(nums1[i]);
        i++;
    } 
    while(j < nums2.size())
    {
        ans.push_back(nums2[j]);
        j++;
    } 
    for(auto x : ans)
    {
        for(int i : x)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}