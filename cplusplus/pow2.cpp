#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 16;
    if(n == 0)
            return false;
        while(n != 0 && n % 2 == 0)
        {
            n /= 2; 
        }
        if(n == 1)
            return true;
        if(n % 2 != 0)
            return false;
        if(n == 0)
            return true;
        return false; 
}