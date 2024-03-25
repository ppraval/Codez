#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int j = 1;
    for (int i = 1; i < nums.size(); i++) 
    {
        if (j == 1 || nums[i] != nums[j - 2]) 
        {
            nums[j++] = nums[i];    
        }
    }
    for(int i = 0; i < j; i++)
        cout << nums[i] << " ";
    return j;
}