#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int key;
    int p;
} *item;

typedef struct pq
{
    item *array;
    int size;
} *pq;

pq createQueue(int max)
{
    pq queue = (pq) malloc(sizeof(pq));
    queue->array = (item) malloc(max * size(item));
    queue->size = 0;
    return queue;
}

void insertItem(pq queue, int key, int p)
{
    int i = queue->size - 1;
    while( i >= 0 && queue->array[i].p < p)
    {
        queue->array[i + 1] = queue->array[i];
        i--;
    }
    queue.array[i + 1].key = key;
    queue.array[i + 1].p = p;
    queue.size++;
}

int main()
{
    pq queue = createQueue(10);
    insertItem(queue, 4, 1);
    insertItem(queue, 10, 3);
    insertItem(queue, 8, 5);
    insertItem(queue, 6, 6);
    insertItem(queue, 3, 8);
    insertItem(queue, 5, 10);
    
    for(int i = 0; i < queue->size; i++)
    {
        printf("%d,%d ", queue->array[i]->key, queue->array[i]->p);
    }
    return 0;
}