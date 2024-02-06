#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node* next;
};

typedef struct node* node;

struct hash_table
{
    int max_size;
    int size;
    node arr;
};

typedef struct hash_table* hash_table;

node createNode(int val)
{
    node new_node = (node)malloc(sizeof(struct node));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

hash_table createHashTable(int max_size)
{
    hash_table table = malloc(sizeof(struct hash_table));
    table->arr = malloc(sizeof(struct node) * max_size);
    table->max_size = max_size;
    table->size = 0;
    for(int i = 0; i < max_size; i++)
    {
        table->arr[i].next = NULL;
        table->arr[i].val = -1;
    }
    return table;
}

int hash(int val, int max_size)
{
    return val % max_size;
}

hash_table insert(hash_table table, int val)
{
    if(table == NULL || table->size == table->max_size)
    {
        printf("-1\n");
        return table;
    }
    if(table->size == table->max_size)
    {
        printf("Table is full\n");
        return table;
    }
    int i = hash(val, table->max_size);
    if(table->arr[i].next == NULL)
    {
        node temp = createNode(val);
        table->arr[i].next = temp;
        table->size++;
        return table;
    }
    node traverse_node = table->arr[i].next;
    node prev_node = NULL;
    while(traverse_node != NULL)
    {
        if(traverse_node->val > val)
        {
            break;
        }
        if(traverse_node->val == val)
        {
            printf("-1\n");
            return table;
        }
        prev_node = traverse_node;
        traverse_node = traverse_node->next;
    }
    node temp = createNode(val);
    prev_node->next = temp;
    temp->next = traverse_node;
    table->size++;
    return table;
}

void search(hash_table table, int val)
{
    if(table == NULL)
    {
        printf("-1\n");
        return;
    }
    int index = hash(val, table->max_size);
    int i = 0;
    node traverse_node = table->arr[index].next;
    while(traverse_node != NULL)
    {
        if(traverse_node->val == val)
        {
            printf("%d %d\n", index, i);
            return;
        }
        i++;
        traverse_node = traverse_node->next;
    }
    printf("-1\n");
    return;
}

hash_table delete(hash_table table, int val)
{

}

void printElementsInChain(hash_table table, int index)
{
    // if(table->arr[index].next == NULL);
    // {
    //     printf("-1\n");
    //     return;
    // }
    node traverse_node = table->arr[index].next;
    while(traverse_node != NULL)
    {
        printf("%d ",  traverse_node->val);
        traverse_node = traverse_node->next;
    }
    printf("\n");
}

int main()
{
    hash_table table = createHashTable(5);
    table = insert(table, 1);
    table = insert(table, 5);
    table = insert(table, 10);
    table = insert(table, 20);
    table = insert(table, 15);
    table = insert(table, 25);
    table = insert(table, 30);
    table = insert(table, 35);
    printElementsInChain(table, 0);
    search(table, 15);
    printElementsInChain(table, 0);
    return 0;
}