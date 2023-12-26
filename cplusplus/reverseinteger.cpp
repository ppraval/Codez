#include<bits/stdc++.h>
using namespace std;


int main()
{
    int num = 1534236469;
    long val = 0;
    stack<char> s;
    string t = to_string(abs(num));
    for(int i = 0; i < t.size(); i++)
    {
        s.push(t[i]);
    }
    while(!s.empty())
    {
        val = 10 * val + (s.top() - '0');
        s.pop();
    }
    if(num < 0)
    {
        val *= -1;
    }
    if(val < INT_MIN || val > INT_MAX)
        return 0;
    return int(val);
}

// better code
// int reverse(int x) 
// {
//     int rev = 0;
    
//     while(x != 0)
//     {
//         int rem = x % 10 ;
//         if ((rev < INT_MIN / 10) || (rev > INT_MAX / 10))
//             return 0;
//         rev = (rev * 10) + rem;
//         x /= 10;
//     }
//     return rev;
// }