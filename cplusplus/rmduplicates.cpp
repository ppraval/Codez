#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 1, 3};
    int j = 1;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] != nums[i - 1]){
            nums[j] = nums[i];
            j++;
        }
    }
    for(int i = 0; i < j; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n" << j;
    return 0;
}