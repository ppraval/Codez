#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x = 1019;
    int n = x;
    int sum = x % 10;
    while(x != 0)
    {
        x /= 10;
        sum += x % 10;
    }
    if(n % sum == 0)
    {
        cout << sum << endl;
        return sum;
    }
    else
    {
        cout << -1 << endl;
        return -1;
    }
}