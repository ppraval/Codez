#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {0,1};
    int n = nums.size();
    vector<int> a (n + 1, 0);
    for(int i = 0; i < n; i++)
    {
        a[nums[i]]++;
    }
    for(int i = 0; i <= n; i++)
    {
        if(a[i] == 0)
        {
            cout << i << endl;
            return i;
        }
    }
    return 0;
}