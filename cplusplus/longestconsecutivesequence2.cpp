#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {100,4,200,1,3,2};
    unordered_set<int> s;
    int max_len = 1;
    for(int i : nums)
        s.insert(i);
    for(int i : nums)
    {
        if(s.count(i - 1) > 0)
        {
            int j = 0;
            int len = 1;
            while(s.count(i + j) > 0)
            {
                j++;
                len++;
            }
            max_len = max(max_len, len);
        }
    }
    cout << max_len;
    return 0;
}