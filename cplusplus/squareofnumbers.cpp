#include<bits/stdc++.h>
using namespace std;

int main()
{
    int c = 5;
    for(int a = 1; a*a <= c; a++)
    {
        int b = c - a * a;
        if(b == (int)b)
        {
            cout << true;
            return true;
        }
    }
    cout << false;
    return 0;
}