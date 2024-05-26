#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums1 = {1,3,4};
    vector<int> nums2 = {1,3,4};
    int k = 1;
    int count = 0;
    for(int i = 0; i < nums1.size(); i++)
    {
        for(int j = 0; j < nums2.size(); j++)
        {
            if(nums1[i] % (nums2[j] * k) == 0)
            {
                count++;
            }
        }
    }
    cout << count << endl;
    return count;
}