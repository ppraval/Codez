#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = height.size();
    if(n < 3)
        return 0;
    int ans = 0;
    int i = 1, j = n - 2;
    int left = height[0];
    int right = height[n - 1];
    while(i <= j)
    {
        cout << "Left = " << left << " | " << "Right = " << right << endl;
        if(left < right)
        {
            if(height[i] >= left)
            {
                left = height[i];
            }
            else
            {
                ans += left - height[i]; 
            }
            i++;
        }
        else
        {
            if(height[j] >= right)
            {
                right = height[j];
            }
            else
            {
                ans += right - height[j];
            }
            j--;
        }
    }
    cout << ans;
    return 0;
}