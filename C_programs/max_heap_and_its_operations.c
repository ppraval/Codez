#include<stdio.h>

int max_heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if(right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if(largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        max_heapify(arr, n, largest);
    }
    return 0;
}
 
int build_max_heap(int arr[], int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        max_heapify(arr, n, i);
    }
    return 0;
}

int max_element(int arr[])
{
    return arr[0];
}

int heap_extract_max(int arr[], int *n)
{
    if(*n < 0)
    {
        printf("-1\n");
    }
    else
    {
        int max = arr[0];
        int temp = arr[0];
        arr[0] = arr[*n - 1];
        arr[*n - 1] = temp;
        (*n)--;
        max_heapify(arr, *n - 1 ,0);
        return max;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int change_value(int arr[], int i)
{
    int parent = (i - 1) / 2;
    if (parent > 0 && arr[i] > arr[parent])
    {
        int temp = arr[i];
        arr[i] = arr[parent];
        arr[parent] = temp;
        i = parent;
    }
    return 0;
}

int change_priority(int arr[], int key, int val, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            break;
        }
    }
    arr[i] = val;
    build_max_heap(arr, n);
    return 0;
}

int insert_element(int arr[], int key, int *n)
{
    arr[*n] = key;
    (*n)++;
    change_value(arr, ((*n) - 1));
    build_max_heap(arr, *n);
    return 0;
}

int main()
{
    int n = 9, a, k = 3;
    int arr[] = {45, 31, 14, 13, 20, 7, 11, 12, 7};
    
    build_max_heap(arr, n);
    printArray(arr, n);

    printf("%d\n", max_element(arr));

    printf("%d\n", heap_extract_max(arr, &n));
    printArray(arr, n);
    
    change_priority(arr, 14, 49, n);
    printArray(arr, n);

    insert_element(arr, 50, &n);
    printArray(arr, n);
    return 0;
}