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
    Node new_Node = new ListNode(val);
    if(head == NULL)
        return new_Node;
    Node traverse_Node = head;
    while(traverse_Node->next != NULL)
    {
        traverse_Node = traverse_Node->next;
    }
    traverse_Node->next = new_Node;
    return head;
}

void printList(Node head)
{
    Node traverse_Node = head;
    if(head == NULL)
    {
        cout << -1 << endl;
        return;
    }
    while(traverse_Node != NULL)
    {
        cout << traverse_Node->val << " ";
        traverse_Node = traverse_Node->next;
    }
    cout << endl;
    return;
}

Node rotateRight(Node head, int k)
{
    if(k == 0)
        return head;
    if(head == NULL)
        return head;
    if(head->next == NULL)
        return head;
    Node traverse_Node = head;
    int count = 0;
    while(traverse_Node != NULL)
    {
        count++;
        traverse_Node = traverse_Node->next;
    }
    if(k % count == 0)
        return head;
    Node previous_Node = head;
    traverse_Node = head;
    for(int i = 0; i < count - (k % count); i++)
    {
        previous_Node = traverse_Node;
        traverse_Node = traverse_Node->next;
    }
    previous_Node->next = NULL;
    Node temp_Node = traverse_Node;
    while(temp_Node->next != NULL)
    {
        temp_Node = temp_Node->next;
    }
    temp_Node->next = head;
    return traverse_Node;
}

int main()
{
    Node head = NULL;
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    // head = insertNode(head, 4);
    // head = insertNode(head, 5);
    head = rotateRight(head, 2);
    printList(head);
    return 0;   
}