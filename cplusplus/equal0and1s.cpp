#include<bits/stdc++.h>
using namespace std;


int main()
{
    vector<int> nums = {0,1};
    int n = nums.size();
    unordered_map<int, int> mp;
    int sum = 0;
    int max_length = 0;
    for (int i = 0; i < n; i++) 
    {
        // sum += nums[i] == 0 ? -1 : 1;
        if(nums[i] == 0)
            sum += -1;
        else   
            sum += 1; 
        if(sum == 0) 
        {
            max_length = i + 1;
        } 
        else if(mp.find(sum) != mp.end()) 
        {
            max_length = max(max_length, i - mp[sum]);
        }
        else 
        {
            mp[sum] = i;
        }
    }
    cout << max_length << endl;
    return max_length;
}