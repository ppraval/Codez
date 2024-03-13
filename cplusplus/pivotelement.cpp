#include<bits/stdc++.h>
using namespace std;

int getSum(int n)
{
    return (n * (n + 1)) / 2;
}

int main()
{
    int n = 8;
    int sum = getSum(n);
    for(int i = 1; i <= n; i++)
    {
        int first = getSum(i), second = sum - first + i;
        if(first == second) 
        {    
            cout << i << endl;
            return i;
        }
    }
    cout << -1 << endl;
    return -1;
}