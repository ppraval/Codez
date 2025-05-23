#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    int n1 = nums1.size(), n2 = nums2.size(), i = 0, j = 0;
    vector<int>ans;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    while(i < n1 && j < n2)
    {
        if(nums1[i] < nums2[j]) 
            i++;
        else if(nums1[i] == nums2[j]) 
        {
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
        else if(nums1[i] > nums2[j]) 
            j++;
    }
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for(int x : ans)
        cout << x << " ";

    return 0;
}