#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 27;
    double x = (double)n;
    while(1)
    {
        if(x == 1)
        {
            cout << "true";
            return true;
        }
        else if (x <= 0)
        {
            cout << "false";
            return false;
        }
        x /= 3;
    }    
    cout << "false";
    return false;
}