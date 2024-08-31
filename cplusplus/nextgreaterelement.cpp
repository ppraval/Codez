#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {4,5,2,25};
    stack<int> s;
    s.push(nums[0]);
    for(int i : nums)
    {
        while(s.empty() == false && s.top() < i)
        {
            cout << i << " ";
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())
    {
        cout << "-1" << " ";
        s.pop();
    } 
    return 0;
}