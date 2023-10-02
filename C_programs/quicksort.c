#include <stdio.h>

int partition(int arr[], int first, int last)
{
    int i, pivot, temp;

    pivot = arr[last];
    i = first - 1;

    for(int j = first; j <= last - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[last];
    arr[last] = temp;
    return (i + 1);
}

int quick_sort(int arr[], int first, int last)
{
    int n;
    if(first < last)
    {
        n = partition(arr, first, last);
        quick_sort(arr, first, n - 1);
        quick_sort(arr, n + 1, last);
    }
    return 0;
}

int main()
{
    int arr[10] = {1, 3, 24, 33, 453, 8, 543, 53, 4};
    int n = 10;
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}