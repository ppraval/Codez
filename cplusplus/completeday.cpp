#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {12,12,30,24,24};
    int count = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = i + 1; j < nums.size(); j++)
        {
            if((nums[i] + nums[j]) % 24 == 0)
            {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}