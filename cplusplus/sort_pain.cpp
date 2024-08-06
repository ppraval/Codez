#include<bits/stdc++.h>
using namespace std;

void sort_pain(int arr[], int n)
{
    sort(arr, arr + n);
}

int main()
{
    int arr[10] = {1,2,3,5,4,6,1,2,0,10};
    cout << "The pre-sorted array is " << endl;
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;
    sort_pain(arr, 10);
    cout << "The sorted array is " << endl;
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    return 0;
}