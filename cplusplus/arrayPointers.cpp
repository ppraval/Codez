#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    cout << arr << endl; // Address of the first element
    cout << &arr[0] << endl; // Address of the first element
    cout << arr + 1 << endl; // Address of the second element
    cout << &arr[1] << endl; // Address of the second element
    return 0;
}