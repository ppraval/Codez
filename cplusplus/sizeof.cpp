#include<bits/stdc++.h>
using namespace std;

int main()
{
    // sizeof()
    int a[2];
    cout << &a[0] << " " << &a[1] << endl;
    cout << ((char*)&a[1] - (char*)&a[0]) << " bytes apart" << endl;
}