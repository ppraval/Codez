#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 6;
    vector<int> arr = {900,945,955,1100,1500,1800};
    vector<int> dep = {920,1200,1130,1150,1900,2000};
    int ans = 1;
    int count = 1;
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int i = 1;
    int j = 0;
    while(i < n && j < n)
    {
        if(arr[i] <= dep[j])
        {
            count++;
            i++;
        }
        else
        {
            count--;
            j++;
        }
        ans = max(ans, count);
    }
    cout << ans; 
    return 0;
}