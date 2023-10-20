#include <stdio.h>

int min_heapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if(left < n && arr[left] < arr[smallest])
    {
        smallest = left;
    }
    if(right < n && arr[right] < arr[smallest])
    {
        smallest = right;
    }
    if(smallest != i)
    {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        min_heapify(arr, n, i);
    }
    return 0;
}

int build_min_heap(int arr[], int n)
{
    for (int i = ((n)/2) - 1; i >= 0; i--)
    {
        min_heapify(arr, n, i);
    }
}

int heap_minimum(int arr[])
{
    return arr[0];
}

int heap_extract_min(int arr[], int *n)
{
    if(*n < 0)
    {
        printf("-1\n");
    }
    else
    {
        int min = arr[0];
        int temp = arr[0];
        arr[0] = arr[*n - 1];
        arr[*n - 1] = temp;
        (*n)--;
        min_heapify(arr, *n, 1);
        return min;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int changeValue(int arr[], int i)
{
    int parent = i / 2;
    if ( parent > 0 && arr[i] < arr[parent])
    {
        int temp = arr[i];
        arr[i] = arr[parent];
        arr[parent] = temp;
        i = parent;
    }
    return 0;
}

int insertElement(int arr[], int key, int *n)
{
    arr[*n] = key;
    (*n)++;
    changeValue(arr, ((*n) - 1));
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    build_min_heap(arr, n);
    printArray(arr, n);
    printf("\n");
    
    printf("%d\n", heap_minimum(arr));

    printf("%d\n", heap_extract_min(arr, &n));

    printArray(arr, n);
    printf("\n");

    insertElement(arr, 6, &n);

    printArray(arr, n);
    
    return 0;
}

