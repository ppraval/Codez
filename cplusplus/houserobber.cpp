#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,2,3,1};
    int rob = 0, safe = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        int new_rob = safe + nums[i];
        int new_safe = max(safe, rob);
        rob = new_rob;
        // cout << "rob = " <<  rob << endl;
        safe = new_safe;
        // cout << "safe = " << safe << endl << endl;
    }
    int ans = max(rob, safe);
    cout << ans << endl;
    return ans;
}