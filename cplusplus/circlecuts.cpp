#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3;
    if(n == 1)
        return 1;
    if(n % 2 == 0)
        return n / 2;
    return n;
}