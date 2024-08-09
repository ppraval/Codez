#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 13224;
    int sum = 0;
    while(n)
    {
        sum += n % 10;
        cout << n % 10 << endl;
        n /= 10;
        cout << "The value of n is " << n << endl;
    }
    cout << endl;
    cout << sum << endl;
    return 9;
}