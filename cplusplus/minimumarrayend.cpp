#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3, x = 4;
    long long y = x;
    for(int i = 0; i < n - 1; i++)
    {
        y = (y + 1) | x;
    }
    cout << y;
    return y;
}