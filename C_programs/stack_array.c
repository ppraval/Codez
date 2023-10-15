#include<stdio.h>

void push(int arr[], int key, int *top)
{
    (*top)++;
    arr[*top] = key;   
}

void pop(int arr[], int *top)
{
    (*top)--;
}

void printstack (int arr[], int *top)
{
    for (int i = 0; i <= *top; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[10];
    int a = -1;
    int *top = &a;
    push(arr, 5, top);
    push(arr, 2, top);
    push(arr, 3, top);
    push(arr, 7, top);
    push(arr, 6, top);
    pop(arr, top);
    printstack(arr, top);
    return 0;
}