#include<stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct node* newNode(int val)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

struct node* addToList(struct node* head, int val)
{
    struct node* new_temp = newNode(val);
    struct node* node_1 = head;
    while(node_1->next != NULL)
    {
        node_1 = node_1->next;
    }
    node_1->next = new_temp;
    return head;
}

void printList(struct node* head)
{
    while(head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main()
{
    struct node* new_head = newNode(9);
    // printf("%d ", new_head->val);
    new_head = addToList(new_head, 1);
    new_head = addToList(new_head, 0);
    new_head = addToList(new_head, 16);
    new_head = addToList(new_head, 5);
    new_head = addToList(new_head, 3);
    new_head = addToList(new_head, 4);
    printList(new_head);
    return 0;
}