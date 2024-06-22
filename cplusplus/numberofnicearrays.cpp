#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,1,2,1,1};
    int k = 3;
    int n = nums.size(); 
    vector<int> count(n + 1, 0);
    count[0] = 1;
    int ans = 0;
    int sum = 0;
    for(int i : nums)
    {
        sum += i % 2;
        if(sum >= k)
        {
            ans += count[sum - k];
        }
        count[sum]++;
    }
    for(int i : count)
        cout << i << " ";
    cout << endl;
    cout << ans << endl;
    return ans;
}