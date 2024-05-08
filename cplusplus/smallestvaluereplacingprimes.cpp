#include<bits/stdc++.h>
using namespace std;

int sumOfPrimes(int n)
{
    int ans = 0;
    while(n % 2 == 0)
    {
        ans += 2;
        n /= 2;
    }
    int sq = sqrt(n);
    for(int i = 3; i <= sq; i += 2)
    {
        while(n % i == 0)
        {
            ans += i;
            n /= i;
        }
    }
    if(n > 2)
        ans += n;
    return ans;
}

int main()  
{
    int n = 15;
    while(true)
    {
        int ans = sumOfPrimes(n);
        if(n == ans)
        {
            cout << n << endl;
            return n;
        }
        n = ans;
    }
    cout << n << endl;
    return n;
}