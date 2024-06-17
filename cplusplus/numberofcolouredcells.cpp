#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3;
    vector<int> v(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        v[i] = i*i + v[i - 1];
    }
    for(int i : v)
        cout << i << " ";
    cout << endl << v[n];
    return 0;
}