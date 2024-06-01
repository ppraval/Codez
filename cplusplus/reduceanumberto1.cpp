#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "1101";
    int n = s.length() - 1;
    int val = 0;
    int count = 0;
    int base = 1;
    for(int i = n; i >= 0; i--)
    {
        val += base * (s[i] - '0');
        base *= 2;
    }
    while(val != 1)
    {
        if(val % 2 == 0)
        {
            val /= 2;
        }
        else
        {
            val++;
        }
        count++;
    }
    cout << count << endl;
    return count;   
}

