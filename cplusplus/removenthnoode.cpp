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

node deleteNth(node head, int n)
{
    int count = 0;
    node traverse_node = head;
    while(traverse_node != NULL)
    {
        count++;
        traverse_node = traverse_node->next;
    }
    cout << count << endl;
    if(count == 1)
    {
        return NULL;
    }
    traverse_node = head;
    node previous_node = head;
    if(count == n)
    {
        node temp = head->next;
        head->next = NULL;
        return temp;
    }
    for(int i = 0; i < count - n; i++)
    {
        previous_node = traverse_node;
        traverse_node = traverse_node->next;
    }
    previous_node->next = traverse_node->next;
    return head;
}

int main()
{
    node head = NULL;
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = deleteNth(head, 2);
    printList(head);
}