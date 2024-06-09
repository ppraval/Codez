#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    int k = 5;
    vector<int> a (n, 1);
    vector<int> prefix = a;
    while(k--)
    {
        for(int i = 1; i < n; i++)
        {
            a[i] = prefix[i] + a[i - 1];
        }
        prefix = a;
    }
    // cout << a[n - 1] << endl;
    return a[n - 1];
}