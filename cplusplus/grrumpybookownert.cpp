#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> c = {1,0,1,2,1,1,7,5};
    vector<int> g = {0,1,0,1,0,1,0,1};
    int m = 3;
    int n = c.size();
    int curr_sum = 0;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(g[i] == 0)
            sum += c[i];
        else if(i < m)
            curr_sum += c[i];
    }
    int max_curr_sum = curr_sum;
    for(int i = m; i < n; i++)
    {
        curr_sum += c[i] * g[i];
        curr_sum -= c[i - m] * g[i - m];
        max_curr_sum = max(max_curr_sum, curr_sum);
    }
    cout << sum + max_curr_sum;
    return sum + max_curr_sum;
}