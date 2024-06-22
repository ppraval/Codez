#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,2,3,4};
    int count = 0;
    for(int i : nums)
    {
        if(i % 3 == 0)
        {
            continue;
        }
        else
        {
            count++;
        }
    }
    return count;
}