#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "41.01";
    int i=0;
    int sign=1;
    long ans=0;
    while(i < s.length() && s[i]==' ')
        i++;
    if(s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if(s[i] == '+')
        i++;
    while(i < s.length())
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            ans = ans * 10 + (s[i] - '0');
            if(ans > INT_MAX && sign == -1)
                return INT_MIN;
            else if(ans > INT_MAX && sign == 1)
                return INT_MAX;
            i++;
        }
        else
            return ans * sign;
    }
    return (ans * sign);
}