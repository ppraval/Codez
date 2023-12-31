#include<bits/stdc++.h>
using namespace std;

int main()
{
    uint32_t n = 01011;
    int count = 0;
    while(n != 0)
    {
        if(n & 1)
            count++;
        n = n >> 1;
    }
    cout << count;
    return count;
}