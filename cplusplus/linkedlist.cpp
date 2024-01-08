#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

typedef ListNode *ListNode;

ListNode insertNode(ListNode head, int val)
{
    ListNode new_node = new ListNode(val);
    if(head == NULL)
        return new_node;
    ListNode traverse_node = head;
    while(traverse_node->next != NULL)
    {
        traverse_node = traverse_node->next;
    }
    traverse_node->next = new_node;
    return new_node;
}

void printList(ListNode head)
{
    ListNode traverse_node = head;
    if(head == NULL)
    {
        cout << -1 << endl;
        return;
    }
    while(traverse_node != NULL)
    {
        cout << traverse_node->val << " ";
        traverse_node = traverse_node->next;
    }
    cout << endl;
    return;
}
int main()
{
    ListNode head = NULL;
    head = insertNode(head, 1);
    head = insertNode(head, 1);
    head = insertNode(head, 1);
    head = insertNode(head, 1);
    head = insertNode(head, 1);
    head = insertNode(head, 1);
    printList(head);
}