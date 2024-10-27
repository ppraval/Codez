#include<bits/stdc++.h>
using namespace std;

int main()
{
    // vector<int> arr = {7, 10, 1, 3, 6, 9, 2};
    // vector<int> arr = {10, 9, 7, 6, 3, 2, 1};
    // int n = arr.size();
    // int ans = 0;
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = i + 1; j < n; j++)
    //     {
    //         ans = max(ans, arr[j] - arr[i]);
    //     }
    // }
    // cout << ans << endl;
    vector<int> arr = {7, 10, 1, 3, 6, 9, 2};
    int n = 7;
    int arr[n] = {7, 10, 1, 3, 6, 9, 2}; 
    int n = arr.size();
    int ans = 0;
    int min_price = arr[0];
    for(int i = 1; i < n; i++)
    {
        min_price = min(min_price, arr[i]);
        ans = max(ans, arr[i] - min_price);
    }
    cout << ans << endl;
    return 0;
}