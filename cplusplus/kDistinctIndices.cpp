#include<bits/stdc++.h>
using namespace std;

int main()
{
    // vector<int> nums = {3,4,9,1,3,9,5};
    vector<int> nums = {2,2,2,2,2};
    int k = 2;
    int key = 2;
    int n = nums.size();
    vector<int> ans;
    set<int> s;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(abs(i - j) <= k && nums[j] == key)
            {
                // ans.push_back(i);
                s.insert(i);
            }
        }
    }
    for(auto it : s)
        ans.push_back(it);
    for(int i : ans)
        cout << i << " ";
    return 0;
}