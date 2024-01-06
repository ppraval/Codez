#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node* next;
};

typedef struct node *node;

node createNode(int val)
{
    node new_node = (node)malloc(sizeof(struct node));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

node insertNode(node head, int val)
{
    node new_node = createNode(val);
    if(head == NULL)
        return new_node;
    node traverse_node = head;
    while(traverse_node->next != NULL)
    {
        traverse_node = traverse_node->next;
    }
    traverse_node->next = new_node;
    return head;
}

void printList(node head)
{
    if(head == NULL)
    {
        printf("-1\n");
    }
    node traverse_node = head;
    while(traverse_node != NULL)
    {
        printf("%d ", traverse_node->val);
        traverse_node = traverse_node->next;
    }
    printf("\n");
}

node makeLoop(node head, int val)
{
    node traverse_node = head;
    while(traverse_node->next != NULL)
    {
        traverse_node = traverse_node->next;
    }
    node another_traverse_node = head;
    while(another_traverse_node->next != NULL)
    {
        if(another_traverse_node->val == val)
        {
            traverse_node->next = another_traverse_node;
            break;
        }
        another_traverse_node = another_traverse_node->next;
    }
    return head;
}

void checkForLoop(node head)
{
    node fast = head;
    node slow = head;
    while(fast->next != NULL && fast != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            printf("true\n");
            return;
        }
    }
    printf("false\n");
    return;
}

int main()
{
    node head = NULL;
    head = insertNode(head, 10);
    head = insertNode(head, 11);
    head = insertNode(head, 12);
    head = insertNode(head, 13);
    head = insertNode(head, 14);
    printList(head);
    checkForLoop(head);
    head = makeLoop(head, 11);
    checkForLoop(head);
    return 0;
}