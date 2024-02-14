#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    vector<int>pre (nums.size());
    pre[0] = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        pre[i] = nums[i] + pre[i - 1];
    }
    for(int i=0; i < pre.size(); i++)
    {
            if(i==0)
            {
                if(pre[pre.size()-1] - pre[i] == 0) 
                {
                    cout << 0 << endl;
                    return 0;
                }
                continue;
            }
            if(pre[i-1] == pre[pre.size() - 1] - pre[i]) 
            {
                cout << i << endl;
                return i;
            }
    }
    cout << -1 << endl;
    return -1;
}