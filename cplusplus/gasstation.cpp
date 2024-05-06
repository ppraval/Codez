#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> gas = {1,2,3,4,5}, cost = {3,4,5,1,2};
    int n = gas.size();
    int total = 0;
    int fuel = 0;
    int start_index = 0;

    for(int i = 0; i < n; i++)
    {
        total += gas[i] - cost[i];
        fuel += gas[i] - cost[i];
        if(fuel < 0)
        {
            fuel = 0;
            start_index = i + 1;    
        }
    }
    if(total < 0)
    {
        cout << -1;
        return -1;
    }
    else
    {
        cout << start_index;
        return start_index;
    }
    return 0;
}