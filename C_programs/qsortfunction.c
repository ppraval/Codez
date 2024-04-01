#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int arr[] = {2, 1, 4, 6, 3};
    qsort(arr, 5, sizeof(int), cmpfunc);
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}