#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    int arr[38] = {0, 1, 1};
    for(int i = 3; i < 38; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    cout << arr[n];
    return 0;
}