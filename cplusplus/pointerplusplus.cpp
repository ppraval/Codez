#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int a = 10;
    int* ptr = &a;
    ptr++;
    cout << "Address after incrementing pointer: " << ptr << endl;
    ptr--;
    cout << "Address after decrementing pointer: " << ptr << endl;
    ptr += 1;
    cout << "Address after adding 1 to pointer: " << ptr << endl;
    ptr -= 1;
    cout << "Address after subtracting 1 from pointer: " << ptr << endl;
    return 0;
}