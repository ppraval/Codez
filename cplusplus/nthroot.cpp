#include<bits/stdc++.h>
using namespace std;

int power(int n, int m, int mid)
{
    long long ans = 1;
    while(n--)
        ans *= mid;
    if(m == ans)
        return 1;
    if(m < ans)
        return 2;
    return 0;
}

int main()
{
    int n = 3;
    int m = 27;
    int low = 1, high = m;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        int val = power(n, m, mid);
        if(val == 1)
        {
            return mid;
        }
        else if(val == 2)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}