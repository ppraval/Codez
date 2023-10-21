#include <stdio.h>

int heapify(int arr[], int n, int i)
{   
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && arr[left] < arr[smallest])
    {
        smallest = left;
    }
    if (right < n && arr[right] < arr[smallest])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(arr, n, smallest);
    }
    return 0;
}

int build_min_heap(int arr[], int n)
{
    int temp;
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    return 0;
}

int heapsort(int arr[], int n)
{
    int temp;
    build_min_heap(arr, n);
    for (int i = n - 1; i >= 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i]; 
        arr[i] = temp;

        heapify(arr, i, 0);
    }
    return 0;
}

int main()
{
    int arr[10] = {1, 2, 342, 5, 31, 324, 3 ,235, 46};
    int n = 10;

    heapsort(arr, n);

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}