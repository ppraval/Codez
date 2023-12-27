#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(n = n + 1; n < 10000; n++)
    {
        int a =  n / 1000;
        int b = (n / 100) % 10;
        int c = (n / 10) % 10;
        int d = n % 10;
        if(a != b && a != c && a != d && b != c && b != d && c != d)
        {
            cout << n << endl;
            break;
        }
    }
    return 0;
}