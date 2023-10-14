#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *next;
};

typedef struct node *node;

node createNode(int key)
{
    node new_node;
    new_node = (node) malloc(sizeof(struct node));
    new_node->key = key;
    new_node->next = NULL;
    return new_node;
}

node addtoqueue(node head, int key)
{
    node new_node = createNode(key);
    if(head == NULL)
    {
        head = new_node;
        return head;
    }
    else
    {
        node traverse_node;
        traverse_node = head;
        while(traverse_node->next != NULL)
        {
            traverse_node = traverse_node->next;
        }
        traverse_node->next = new_node;
    }
    return head;
}
node displayQueue(node head)
{
    node traverse_node;
    traverse_node = head;
    while(traverse_node != NULL)
    {
        printf("%d ", traverse_node->key);
        traverse_node = traverse_node->next;
    }
    return head;
}
node removefromqueue(node head)
{
    node new_head;
    new_head = head->next;
    free(head);
    return new_head;
}

node nextinqueue(node head)
{
    printf("%d\n", head->key);
    return head;
}

int main()
{
    int num;
    node head = NULL;
    char command, input[100];
    
    while(1)
    {
        fgets(input, 100, stdin);
        sscanf(input, "%c %d", &command, &num);
        if(command == 'a')
        {
            head = addtoqueue(head, num);
        }
        else if(command == 's')
        {
            
        }
        else if(command == 'n')
        {
            head = nextinqueue(head);
        }
        else if(command == 'd')
        {
            head = displayQueue(head);
        }
        else if(command == 'r')
        {
            head = removefromqueue(head);
        }
        else if(command == 'e')
        {
            break;
        }
    }
}