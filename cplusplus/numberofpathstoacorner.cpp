#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m = 3;
    int n = 7;
    int t = m + n - 2;
    int r = m - 1;
    if(r > t - r)
    {
        r = t - r;
    }
    vector<int> c(r + 1, 0);
    cout << endl;
    c[0] = 1;
    for(int i = 1; i <= t; i++)
    {
        for(int j = min(i, r); j > 0; j--)
        {
            c[j] = c[j] + c[j - 1];
        }
    }
    cout << c[r];
    return 0;
}