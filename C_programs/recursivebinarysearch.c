#include <stdio.h>

int recursive_binary_search(int arr[], int key, int high, int low, int mid, int n)
{
    mid = (high + low) / 2;
        if (arr[mid] == key)
        {
           printf("found ya ");
           return 1;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
            return arr, key, high, low, mid, n;
        }
        else
        {
            high = mid - 1;
            return arr, key, high, low, mid, n;
        }
}

int main()
{
    int arr[6] = {2, 4, 6, 7, 8, 12};
    int x, mid, high, low, key = 6;
    high = 5;
    low = 0;
    recursive_binary_search(arr, key, high, low, mid, 6);
    return 0;
}