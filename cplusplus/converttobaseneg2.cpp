#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 12;
    string bin;
    const int base = -2;
    while (n != 0)
    {
        int remainder = n % 2;
        if (remainder == 0)
        {
            bin.push_back('0');
            n = n / base;
        }
        else
        {
            bin.push_back('1');
            n = (n - 1) / base;
        }
    }
    
    reverse(bin.begin(),bin.end());
    cout << bin << endl;
    return 0;
}