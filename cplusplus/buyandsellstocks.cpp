#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {7,1,5,3,6,4};
    int maxprof = 0;
    int min_price = v[0];
    for(int i = 1; i < v.size(); i++)
    {
        if(min_price < v[i])
        {
            maxprof += v[i] - min_price;
        }
        min_price = v[i];
    }
    cout << maxprof << endl;
    return 0;
}