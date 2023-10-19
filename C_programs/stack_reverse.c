#include<stdio.h>

void push(int arr[], int key, int *top)
{
    (*top)++;
    arr[*top] = key;   
}

int pop(int arr[], int *top)
{
    int x = arr[*top];
    (*top)--;
    return x;
}

void printstack (int arr[], int *top)
{
    for (int i = 0; i <= *top; i++)
    {
        printf("%d ", arr[i]);
    }
}

void reversestack(int arr[], int *top, int size)
{
    if(*top != -1)   
    {
        int temp = pop(arr, top);
        reversestack(arr, top, size);
        (*top)++;
        arr[size - *top] = temp;
    }
}

int main()
{
    int arr[10];
    int a = -1;
    int *top = &a;
    push(arr, 1, top);
    push(arr, 2, top);
    push(arr, 3, top);
    push(arr, 4, top);
    push(arr, 5, top);
    push(arr, 6, top);
    push(arr, 7, top);
    printstack(arr, top);
    reversestack(arr, top, *top);
    printf("\n");
    printstack(arr, top);
    return 0;
}