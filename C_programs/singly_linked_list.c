#include <stdio.h>
#include <stdlib.h>

struct linkedList {
    int key;
    struct linkedList *next;
};

typedef struct linkedList *node;

node createNode()
{
    node temp;
    temp = (node) malloc(sizeof(struct linkedList));
    temp->next = NULL;
    return temp;
}

node insertAtBegining(int x, node head)
{
    node temp;
    temp = createNode();
    temp->key = x;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    return head;
}

node insertAtEnd(int x, node head)
{
    node traverse_node, temp;
    temp = createNode();
    temp->key = x;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        traverse_node = head;
        while(traverse_node->next != NULL)
        {
            traverse_node = traverse_node->next;
        }
        traverse_node->next = temp;
    }
    return head;
}

node insertAfterAnother(int x, int existing_key, node head)
{
    node current_node, next_node;
    node temp;
    temp = createNode();
    temp->key = x;
    current_node = head;
    while(current_node->key != existing_key)
    {
        current_node = current_node->next;
    }
    temp->next = current_node->next;
    current_node->next = temp;
    return head;
}

node printList(node head)
{
    node traverse_node = head;
    while(traverse_node != NULL)
    {
        printf("%d - ", traverse_node->key);
        traverse_node = traverse_node->next;
    }
    return head;
}

int main()
{
    node head = NULL;
    head = insertAtBegining(5, head);
    head = insertAtEnd(6, head);
    head = insertAfterAnother(7, 5, head);
    printList(head);
    return 0;
}