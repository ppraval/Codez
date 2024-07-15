#include<bits/stdc++.h>
using namespace std;

bool isValid(int n)
{
    if(n / 1000 == 0)
    {
        int last = n % 10;
        int first = n / 100;
        // first = first % 10;
        int val = first * 10 + last; 
        if(n % val == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n = 191;
    if(n <= 100)
    {
        cout << 100;
        return 100;
    }
    int prev = n - 1, next = n + 1;
    while(!isValid(prev) && !isValid(next))
    {
        prev--;
        next++;
    }
    if(isValid(prev))
    {
        cout << prev;
    }
    else
    {
        cout << next;
    }
    return 0;
}