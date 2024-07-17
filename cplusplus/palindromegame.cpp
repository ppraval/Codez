#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    string s = "10001";
    int one = 0;
    int zero = 0;
    for(char x : s)
    {
        if(x == '1')
            one++;
        else
            zero++;
    }
    if(zero == 1)
        cout << "Bob";
    if(zero % 2 == 0)
        cout << "Bob";
    else
        cout << "Alice";
    return 0;
}