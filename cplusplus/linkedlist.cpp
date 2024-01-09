#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

typedef ListNode* Node;

// class Node
// {
//     public:
//         int val;
//         Node* next;
//         Node(int val) : val(val), 
// }



Node insertNode(Node head, int val)
{
    Node new_node = new ListNode(val);
    if(head == NULL)
        return new_node;
    Node traverse_node = head;
    while(traverse_node->next != NULL)
    {
        traverse_node = traverse_node->next;
    }
    traverse_node->next = new_node;
    return head;
}

void printList(Node head)
{
    Node traverse_node = head;
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
    Node head = NULL;
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);
    head = insertNode(head, 4);
    head = insertNode(head, 5);
    head = insertNode(head, 6);
    printList(head);
}