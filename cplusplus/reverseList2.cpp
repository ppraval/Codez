#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

typedef ListNode* node;

node insertNode(node head, int val)
{
    node new_node = new ListNode(val);
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
    node traverse_node = head;
    while(traverse_node != NULL)
    {
        cout << traverse_node->val << " ";
        traverse_node = traverse_node->next;
    }
    cout << endl;
}

node reverseNode(node head)
{
    if(head == NULL)
    {
        return head;
    }
    node traverse_node = head;
    node previous_node = NULL;
    node next_node = NULL;
    node temp_node;
    while(traverse_node != NULL)
    {
        temp_node = traverse_node->next;
        next_node = traverse_node;
        next_node->next = previous_node;
        previous_node = traverse_node;
        traverse_node = temp_node;
    }
    return next_node;
}

node reverseLinkedList(node head, int left, int right)
{
    node traverse_node = head;
    int count = 0;
    while(traverse_node != NULL)
    {
        count++;
        traverse_node = traverse_node->next;
    }
    node right_list;
    traverse_node = head;
    for(int i = 1; i < right; i++)
    {
        traverse_node = traverse_node->next;
    }
    right_list = traverse_node->next;
    traverse_node->next = NULL;
    traverse_node = head;
    for(int i = 1; i < left - 1; i++)
    {
        traverse_node = traverse_node->next;
    }
    node new_left_start = traverse_node->next;
    traverse_node->next = NULL;
    new_left_start = reverseNode(new_left_start);
    node another_traverse_node = new_left_start;
    while(another_traverse_node->next != NULL)
    {
        another_traverse_node = another_traverse_node->next;
    }
    another_traverse_node->next = right_list;
    traverse_node->next = new_left_start;
    return head;
}

int main()
{
    node head = NULL;
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);
    head = insertNode(head, 4);
    head = insertNode(head, 5);
    printList(head);
    // head = reverseNode(head);
    // printList(head);
    head = reverseLinkedList(head, 2, 4);
    printList(head);
    return 0;
}