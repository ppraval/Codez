#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 22;
    int x = 1;
    if(n < 0) 
    {
        x = 1 / x;
    } 
    long num = labs(n);
    double pow = 1;
    
    while(num)
    {
        if(num & 1) 
        {
            pow *= x;
        }
        x *= x;
        num >>= 1;
    }
    cout << pow;
    return 0;
}