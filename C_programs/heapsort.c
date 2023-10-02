#include <stdio.h>

int heapify(int arr[], int n, int i)
{   
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
    return 0;
}

int build_max_heap(int arr[], int n)
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
    build_max_heap(arr, n);
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