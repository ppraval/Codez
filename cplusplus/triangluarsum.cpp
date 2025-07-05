#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,2,3,4,5};
    vector<vector<int>> triangle;
    triangle.push_back(nums);
    int n = nums.size();
    for(int i = 1; i < n; i++)
    {
        vector<int> temp;
        for(int j = 0; j < nums.size() - 1; j++)
        {
            temp.push_back((nums[j] + nums[j + 1]) % 10);
        }
        // for(int i : temp) 
        //     cout << i << " ";
        // cout << endl;
        triangle.push_back(temp);
        nums = temp;
    }
    cout << triangle[n - 1][0] << endl;
    return 0;
}