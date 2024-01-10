#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int val) : val(val), next(nullptr) {};
    ListNode(int val, ListNode *next) : val(val), next(next) {};
};

typedef ListNode* node;

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

node insertNode(node head, int val)
{
    node new_node = new ListNode(val);
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

void binaryToInt(node head)
{
    node traverse_node = head;
    int val = 0;
    while(traverse_node != NULL)
    {
        val = val * 10 + traverse_node->val;
        traverse_node = traverse_node->next;
    }
    int dec = 0, i = 0, rem;
    while(val != 0)
    {
        rem = val % 10;
        val /= 10;
        dec += rem * pow(2, i);
        i++;
    }
    cout << dec << endl;
}

int main()
{
    node head = NULL;
    head = insertNode(head, 1);
    head = insertNode(head, 0);
    head = insertNode(head, 1);
    binaryToInt(head);
    return 0;
}