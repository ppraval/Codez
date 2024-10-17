#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str = "110";
    int n = str.size();
    int count_0 = 0;
    
    int count_1 = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(str[i] == '1')
        {
            count_1++;
        }
        else
        {
            count_0++;
        }
    }
    if(abs(count_1 - count_0) >= 2)
        return -1;
    int uncommon_1 = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            if(str[i] != '0')
            {
                uncommon_1++;
            }
        }
        else
        {
            if(str[i] != '1')
            {
                uncommon_1++;
            }
        }
    }
    int uncommon_2 = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 1)
        {
            if(str[i] != '0')
            {
                uncommon_2++;
            }
        }
        else
        {
            if(str[i] != '1')
            {
                uncommon_2++;
            }
        }
    }
    int mini = INT_MAX;
    
    if(uncommon_1 % 2 == 0)
    {
        mini = min(mini, uncommon_1);
    }
    
    if(uncommon_2 % 2 == 0)
    {
        mini = min(mini, uncommon_2);
    }
    if(mini == INT_MAX)
        return -1;
    cout << mini / 2;
    return (mini) / 2;
}