#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ans;
    for(int i = 0; i < nums.size(); i++)
    {
        int num = abs(nums[i]);
        int index = num - 1;
        if(nums[index] < 0)
        {
            ans.push_back(num);
        }
        nums[index] *= -1;
        cout << num << endl;
        cout << "nums =" << endl;
        for(int j : nums)
            cout << j << " ";
        cout << endl << "ans =" << endl;
        for(int j : ans)
            cout << j << " ";
        cout << endl;
    }
    for(int i : ans)
        cout << i << " ";
    return 0;
}