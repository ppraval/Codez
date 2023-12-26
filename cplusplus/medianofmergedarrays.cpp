#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    for(int i = 0; i < nums2.size(); i++)
    {
        nums1.push_back(nums2[i]);
    }
    sort(nums1.begin(), nums1.end());
    int n = nums1.size();
    cout << n << endl;
    if(n % 2 == 1)
    {
        cout << nums1[n / 2] << endl;
        return nums1[n / 2];
    }
    else
    {
        cout << "mid = " << nums1[n / 2] << " mid - 1 = " << nums1[(n / 2) - 1] << endl;
        cout << nums1[n / 2] + nums1[(n - 1) / 2] << endl;
        cout << (double) (nums1[n / 2] + nums1[(n - 1) / 2]) / 2 << endl;
        return (nums1[n / 2] + nums1[(n - 1) / 2]) / 2;
    }
}