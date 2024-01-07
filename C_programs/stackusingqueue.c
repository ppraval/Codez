#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int front;
    int end;
    int arr[100];
};

typedef struct queue *queue;

queue createQueue(queue q)
{
    q->front = -1;
    q->end = -1;
    return q;
}

queue enqueue(queue q, int val)
{
    if(q->front == -1)
        q->front++;
    q->end++;
    q->arr[q->end] = val;
    return q;
}

queue dequeue(queue q)
{
    q->front++;
    return q;
}

void printQueue(queue q)
{
    for(int i = q->front; i <= q->end; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

queue push(queue q, queue q1, int val)
{
    while(q->front != q->end + 1)
    {
        q1 = enqueue(q1, q->arr[q->front]);
        q = dequeue(q);
    }
    printf("The q1 is = ");
    printQueue(q1);
    q = enqueue(q, val);
    printf("The q is = ");
    printQueue(q);
    while(q1->front != q1->end + 1)
    {
        q = enqueue(q, q1->arr[q1->front]);
        q1 = dequeue(q1);
    }
    return q;
}

queue pop(queue q)
{
    q = dequeue(q);
    return q;
}

int main()
{
    queue q, q1;
    q = createQueue(q);
    q1 = createQueue(q1);
    q = enqueue(q, 0);
    q = enqueue(q, 1);
    q = enqueue(q, 2);
    q = enqueue(q, 3);
    q = enqueue(q, 4);
    printQueue(q);
    q = dequeue(q);
    printQueue(q);
    q = push(q, q1, 0);
    printQueue(q);
    printf("The second push doenst seem to work for some reason\n");
    printf("How does q1 look = ");
    printQueue(q1);
    printf("does q remain the same? = ");
    printQueue(q);
    q = push(q, q1, 0);
    printQueue(q);
    return 0;
}