#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3;
    int time = 2;
    int dir = 1;    
    int sum = 0;
    for(int i = 0; i < time; i++)
    {
        if(dir == 1 && sum == n - 1)
        {
            dir = -1;
        }
        else if(dir == -1 && sum == 0)
        {
            dir = 1;
        }
        sum += dir;
        cout << sum << " ";
    }   
    cout << endl << sum + 1;
    return 0;
}