#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    int res = 0;
    for (int i = 2; i <= n; i++) 
    {
        while (n % i == 0) 
        {
            res += i;
            n /= i;
        }
    }
    cout << res << endl;
    return res;
}

