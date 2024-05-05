#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums1 = {2, 6, 4};
    vector<int> nums2 = {9, 7, 5};
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    cout << nums2[0] - nums1[0];
    return 0;
}