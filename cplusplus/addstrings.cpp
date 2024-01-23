#include<bits/stdc++.h>
using namespace std;

int main()
{
    string num1 = "11";
    string num2 = "123";
    int a = stoi(num1);
    int b = stoi(num2);
    int c = a + b;
    string res = to_string(c);
    cout << c << endl;
    return 0;
}