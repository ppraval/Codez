#include<bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if(n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    string num = "123";
    int n = num.length();
    n = factorial(n);
    int count = 0;
    while(n--)
    {
        int even_sum = 0;
        int odd_sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
                even_sum += (num[i] - '0');
            else
                odd_sum += (num[i] - '0');
        }
        if(even_sum == odd_sum)
        {
            count++;
        }
        num = next_permutation(num.begin(), num.end());
    }
    cout << count << endl;
    return 0;
}