#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num = 19;
    if(num == 0) 
        return 0;
    else if(num % 9 == 0) 
        return 9;
    else 
        return num % 9;
}