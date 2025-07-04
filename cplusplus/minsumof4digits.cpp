#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num = 2932;
    string s = to_string(num);
    sort(s.begin(), s.end());
    string num1 = "";
    num1 += s[0];
    num1 += s[2];
    string num2 = "";   
    num2 += s[1];
    num2 += s[3];   
    cout << num1 << " " << num2 << endl;
    int sum = stoi(num1) + stoi(num2);
    cout << sum << endl;
    return 0;
}