#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3;
    vector<int> catlan(n + 1, 0);
    catlan[0] = catlan[1] = 1;
    for(int i=2; i <= n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            catlan[i] += catlan[j] * catlan[i - j - 1];
        }
    }
    cout << catlan[n] << endl;
    return 0;
}