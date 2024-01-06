#include<stdio.h>
#include<stdlib.h>

struct node
{
    int  val;
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
    {
        return new_node;
    }
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
    node traverse_node = head;
    if(head == NULL)
    {
        printf("-1\n");
    }
    while(traverse_node != NULL)
    {
        printf("%d ", traverse_node->val);
        traverse_node = traverse_node->next;
    }
    printf("\n");
}

node reverseList(node head)
{
    if(head == NULL)
    {
        return head;
    }
    node previous_node = NULL, current_node = head, next_node = head, temp_node;
    while(current_node != NULL)
    {
        temp_node = current_node->next;
        next_node = current_node;
        next_node->next = previous_node;
        previous_node = current_node;
        current_node = temp_node;
    }
    return next_node;
}

node reverseFirstKList(node head, int k)
{
    node list1;
    node list2;
    int i = 1;
    node traverse_node = head;
    while(traverse_node != NULL && i < k)
    {
        traverse_node = traverse_node->next;
        i++;
    }
    list2 = traverse_node->next;
    traverse_node->next = NULL;
    list1 = head;
    list1 = reverseList(list1);
    traverse_node = list1;
    while(traverse_node->next != NULL)
    {
        traverse_node = traverse_node->next;
    }
    traverse_node->next = list2;
    return list1;
}

int main()
{
    node head = NULL;
    head = insertNode(head, 15);
    head = insertNode(head, 14);
    head = insertNode(head, 13);
    head = insertNode(head, 12);
    head = insertNode(head, 11);
    head = reverseList(head);
    printList(head);
    head = reverseFirstKList(head, 3);
    printList(head);    
    return 0;
}