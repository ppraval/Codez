#include<stdio.h>
#include<stdlib.h>

void enqueue(int arr[], int key, int *front, int *rear)
{
    (*rear)++;
    arr[*rear] = key;
    if (*front == -1)
    {
        *front = 0;
    }
}

void dequeue(int arr[], int *front)
{
    (*front)++;
}

void displayqueue(int arr[], int *front, int *rear)
{
    for (int i = *front; i <= *rear; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[10];
    int a = -1, b = -1;
    int *front = &a;
    int *rear = &b;
    enqueue(arr, 5, front, rear);
    enqueue(arr, 8, front, rear);
    enqueue(arr, 9, front, rear);
    enqueue(arr, 7, front, rear);
    enqueue(arr, 6, front, rear);
    dequeue(arr, front);
    displayqueue(arr, front, rear);
    return 0;
}