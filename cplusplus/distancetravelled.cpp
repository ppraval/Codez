#include<bits/stdc++.H>
using namespace std;

int main()
{
    int mainTank = 5;
    int additionalTank = 10;
    int count = 0;
    int n = mainTank;
    while(n >= 5 && additionalTank > 0)
    {
        n = (n - 5) + 1;
        additionalTank -= 1;
        count++;  
    }
    cout << (mainTank + count) * 10;
    return 0;
}