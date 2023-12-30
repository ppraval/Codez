#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    if(n <= 2)
        return n;
    vector<int> fibb = {0, 1, 2};
    for(int i = 3; i <= n; i++)
    {
        fibb[i] = fibb[i - 1] + fibb[i - 2];
    }
    cout << fibb[n];
    return fibb[n];
}