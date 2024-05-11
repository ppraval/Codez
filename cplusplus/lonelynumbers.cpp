#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,3,5,3};
    set<int> s;
    vector<int> ans;
    for(int i : nums)
        s.insert(i);
    for(int i : nums)
    {
        if(!s.count(i + 1) && !s.count(i - 1))
        {
            ans.push_back(i);
        }
    }
    for(int i : ans)
        cout << i << " ";
    return 0;
}