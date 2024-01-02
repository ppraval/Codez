#include<bits/stdc++.h>
using namespace std;

int binaryToDecimal(string n) 
{
  bitset<32> bits(n);
  unsigned long decimal_value = bits.to_ulong();
  return decimal_value;
}

int main()
{
    string a = "11";
    string b = "1";
    int num1 = binaryToDecimal(a);
    int num2 = binaryToDecimal(b);
    bitset<32> bits(num1 + num2);
    string binary_string = bits.to_string();
    int i;
    for(i = 0; i < 32; i++)
    {
        if(binary_string[i] == '1')
        {
            break;
        }
    }
    string res = "";
    for(int j = i; j < 32; j++)
    {
        res.push_back(binary_string[j]);
    }
    cout << res;
    return 0;
}