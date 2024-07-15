#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> w = {2, 5, 4, 7, 1, 3, 8};
    int c = 10; 
    int n = w.size();
    int res = 0;
    vector<int> bin_rem(n);
    for(int i = 0; i < n; i++)
    {
        int j;
        int min = c + 1, bi = 0;
        for(int j = 0; j < res; j++)
        {
            if(bin_rem[j] > w[i] && bin_rem[j] - w[i] < min)
            {
                bi = j;
                min = bin_rem[j] - w[j];
            }
        }
        if(min == c + 1)
        {
            bin_rem[res] = c - w[i];
            res++;
        }
        else
        {
            bin_rem[bi] -= w[i];
        }
    }
    cout << res << endl;
    return 0;
}