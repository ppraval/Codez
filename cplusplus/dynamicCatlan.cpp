#include<bits/stdc++.h>
using namespace std;



int catlanRecursive(int n)
{
    if(n <= 1)
    {
        return 1;
    }
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        res += catlanRecursive(i) * catlanRecursive(n - i - 1);
    }
    return res;
}

int catlanDynamic(int n)
{
    vector<int> catlan(n + 1, 0);
    catlan[0] = catlan[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j < i; ++j)
        {
            catlan[i] += catlan[j] * catlan[i - j - 1];
        }
    }
    return catlan[n];
}

int catlanBinomial(int n)
{
    int res = 1;
    cout << res << " ";
    for(int i = 1; i < n; i++)
    {
        res = (res * (4 * i - 2)) / (i + 1);
        cout << res << " ";
    }
    return 0;
}

int main()
{
    int n = 10;
    cout << "The recursive Catlan Numbers are: \n";
    
    for(int i = 0; i < n; i++)
        cout << catlanRecursive(i) << " ";
    
    cout << "\nThe Dynamic Programming Catlan Numbers are: \n";
    
    for(int i = 0; i < n; i++)
        cout << catlanDynamic(i) << " ";

    cout << "\nThe Binomial Coeffs Catlan Numbers are : \n";
    catlanBinomial(n);
    return 0;
}