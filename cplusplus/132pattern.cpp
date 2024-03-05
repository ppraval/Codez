#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {3, 1, 4, 2};
    stack<int> s;
    int third = INT_MIN;

    for(int i = nums.size() - 1; i >= 0; i--)
    {
        if(nums[i] < third)
        {
            cout << true << endl;
            return true;
        }
        while(!s.empty() && s.top() < nums[i])
        {
            third = s.top();
            s.pop();
        }
        s.push(nums[i]);
    }
    cout << false << endl;
    return false;
}