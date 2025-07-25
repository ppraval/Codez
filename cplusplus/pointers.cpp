#include<bits/stdc++.h>
using namespace std;

int main()
{
    int price = 10;
    int* price_pointer = &price; // Pointer to the price variable
    cout << "Value of price: " << *price_pointer << endl;
    return 0;
}