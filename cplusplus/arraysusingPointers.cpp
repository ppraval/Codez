#include<bits/stdc++.h>
using  namespace std;

int main()
{
    int **arr = (int**)malloc(5 * sizeof(int*));

    for (int i = 0; i < 5; i++) 
    {
        arr[i] = (int*)malloc(5 * sizeof(int));
    }   
    // fill the array with some values
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            arr[i][j] = i * 5 + j;
        }
    }
    // print the array
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}