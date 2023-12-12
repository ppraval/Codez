#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str1 = "LEET";
    string str2 = "CODE";
    string result;
    if (str1 + str2 != str2 + str1)
        result = "";    
    else
        result = str2.substr(0, gcd(str1.size(), str2.size()));
    cout << "The gcd of the strings is: " << result;
    return 0;
}