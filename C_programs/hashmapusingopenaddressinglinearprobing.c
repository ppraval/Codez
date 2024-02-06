#include<stdio.h>
#include<stdlib.h>


struct pair
{
    int key;
    int val;
};

typedef struct pair* pair;

struct hash_table
{
    int max_size;
    int size;
    pair arr;
};

typedef struct hash_table* hash_table;

hash_table createHashTable(int max_size)
{
    hash_table new_table = malloc(sizeof(struct hash_table));
    new_table->max_size = max_size;
    new_table->size = 0;
    new_table->arr = malloc(sizeof(struct pair) * max_size);

    for(int i = 0; i < max_size; i++)
    {
        new_table->arr[i].key = -1;
        new_table->arr[i].val = 0;
    }
    return new_table;
}

int hash(int key, int max_size)
{
    return key % max_size;
}

void insert(hash_table table, int key)
{
    if(table == NULL)
    {
        printf("-1\n");
        return;
    }
    if(table->size == table->max_size)
    {
        printf("Table is full\n");
        return;
    }
    int index = hash(key, table->max_size);
    int i = index;

    while(table->arr[i].key != -1 && table->arr[i].key != key)
    {
        i = (i + 1) % table->size;
        if(i == index)
        {
            printf("The table is full\n");
            return;
        }
    }
    table->arr[i].key = key;
    table->arr[i].val++;
    table->size++;
}


int search(hash_table table, int key)
{
    if(table == NULL)
    {
        return -1;
    }
    int index = hash(key, table->max_size);
    int i = index;
    while(table->arr[i].key != -1)
    {
        if(table->arr[i].key == key)
        {
            return table->arr[i].val;
        }
        i = (i + 1) % table->max_size;
        if(i == index)
        {
            return 0;
        }
    }
    return -1;
}


void delete(hash_table table, int key)
{
    if(table == NULL)
    {
        printf("-1\n");
        return;
    }
    int index = hash(key, table->max_size);
    int i = index;
    while(table->arr[i].key != -1)
    {
        if(table->arr[i].key == key)
        {
            table->arr[i].key = -1;
            table->arr[i].val = 0;
            table->size--;
            return;
        }
        i = (i + 1) % table->max_size;
        if(i == index)
        {
            printf("The key is not found\n");
            return;
        }
    }
}

void print_hash_table(hash_table table) 
{
    if (table == NULL) 
    {
        return;
    }
    for (int i = 0; i < table->max_size; i++) 
    {
        if (table->arr[i].key != -1) 
        {
            printf("Key: %d, Value: %d\n", table->arr[i].key, table->arr[i].val);
        }
    }
    printf("\n");
}

int main()
{
    hash_table table = createHashTable(100);
    insert(table, 10);
    insert(table, 10);
    insert(table, 10);
    insert(table, 10);
    insert(table, 10);
    insert(table, 10);
    insert(table, 10);
    insert(table, 10);
    insert(table, 20);
    insert(table, 30);
    insert(table, 40);
    insert(table, 50);
    insert(table, 110);
    
    printf("Value for key 10: %d\n", search(table, 10));
    printf("Value for key 110: %d\n", search(table, 110)); 
    printf("Value for key 50: %d\n", search(table, 50)); 
    
    // delete(table, 10);
    // printf("Value for key 10: %d\n", search(table, 10));

    print_hash_table(table);

    return 0;

}