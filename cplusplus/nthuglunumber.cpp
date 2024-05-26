#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    vector<int> v(n);
    v[0] = 1;
    int f2 = 0, f3 = 0, f5 = 0;
    for(int i = 1; i < n; i++)
    {
        int num = min({v[f2] * 2, v[f3] * 3, v[f5] * 5,});
        v[i] = num;
        if(num == v[f2] * 2)
        {
            f2++;
        }
        if(num == v[f3] * 3)
        {
            f3++;
        }
        if(num == v[f5] * 5)
        {
            f5++;
        }
    }
    cout << v[n - 1];
    return v[n - 1];
}