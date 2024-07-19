#include<bits/stdc++.h>
using namespace std;

int rec(int n, int i)
{
    if(i >= n)
    {
        return 1;
    }
    int count = rec(n, i + 1);
    int count2 = rec(n, i + 2);
    return count + count2;
}

int main()
{
    int n = 3;
    cout << rec(n - 1, 0);
    return 0;
}