#include <stdio.h>

int recursive_linear_search(int arr[],int key, int n)
{
    if (arr[n - 1] == key)
    {
        printf("found ya");
        return 0;
    }
    else
    {
        return arr, n - 1;
    }
}


int main()
{
    int arr[10] = {3, 4, 5, 6, 7, 1, 78, 29, 73};
    int key = 786;
    recursive_linear_search(arr, key, 10);
    return 0;
}