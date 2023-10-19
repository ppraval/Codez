#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int key;
    int p;
    struct node *next;
};

typedef struct node *node;

node createNode(int key, int p)
{
    node temp;
    temp = (node) malloc(sizeof(struct node));
    temp->key = key;
    temp->p = p;
    temp->next = NULL;
    return temp;
}

node addNode(node head, int key, int p)
{
    node new_node, current_node, previous_node = NULL;
    new_node = createNode(key, p);
    
    if(head == NULL)
    {
        head = new_node;
        return head;
    }

    current_node = head;
    while(current_node != NULL && current_node->p >= p)
    {
        if (current_node->key == key && current_node->p > p)
        {
            break;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
    if(previous_node == NULL)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        previous_node->next = new_node;
        new_node->next = current_node;
    }
    return head;
}

node removeNode(node head)
{
    node new_head = head->next;
    free(head);
    return new_head;
}

void printQueue(node head)
{
    node traverse_node = head;
    while(traverse_node != NULL)
    {
        printf("%d,%d ", traverse_node->key, traverse_node->p);
        traverse_node = traverse_node->next;
    }
}

int main()
{
    node head = NULL;
    head = addNode(head, 44, 1);
    head = addNode(head, 12, 6);
    head = addNode(head, 32, 2);
    head = addNode(head, 24, 2);
    head = addNode(head, 64, 4);
    head = removeNode(head);
    printQueue(head);
    return 0;
}
