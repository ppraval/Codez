#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = arr.size();
    vector<int> dp(n + 1, 1);
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);  
            }
        }
    }
    cout << *max_element(begin(dp), end(dp));
    return 0;
}