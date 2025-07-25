#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a = 5, b = 10;
    int *ptr_a = &a; // Pointer to a
    int *ptr_b = &b; // Pointer to b
    cout << ptr_a - ptr_b << endl;
    cout << (char*)ptr_a - (char*)ptr_b << endl;
    return 0;
}