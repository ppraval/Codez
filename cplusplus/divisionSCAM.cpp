#include<bits/stdc++.h>
using namespace std;

int main()
{
    int dividend = 10;
    int divisor = 5;
    if( dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    long long int ans = dividend / divisor;
    if(ans>INT_MAX)
        return INT_MAX;
    if(ans<INT_MIN)
        return INT_MIN;
    return ans;
}