#include<bits/stdc++.h>
using namespace std;

int main()
{
    string num1 = "123";
    string num2 = "456";
    string res = "";
    int a = 0, b = 0;
    for(int i = 0; i < num1.length(); i++)
        a = a * 10 + num1[i] - '0';
    for(int i = 0; i < num2.length(); i++)
        b = b * 10 + num2[i] - '0';
    int n = a * b;
    while (n > 0) 
    {
        res += (n % 10) + '0';
        n /= 10;
    } 
    reverse(res.begin(), res.end());
    cout << res;
    return 0;
}

// Do this code using the Multiplication algorithm