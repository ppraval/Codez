#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(NULL) {}
};

typedef struct ListNode* node;

node createList()
{
    node head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    return head;
}

node reverseList(node head)
{
    node prev_node = NULL;
    node curr_node = head;
    while(curr_node != NULL)
    {
        cout << "Before update" << endl;
        if(prev_node == NULL)
        {
            cout << "prev is NULL" << endl; 
        }        
        else
        {
            cout << "prev is " << prev_node->val << endl;
        }
        if(curr_node == NULL)
        {
            cout << "curr is NULL" << endl; 
        }        
        else
        {
            cout << "curr is " << curr_node->val << endl;
        }
        if(curr_node->next == NULL)
        {
            cout << "next is NULL" << endl; 
        }        
        else
        {
            cout << "next is " << curr_node->next->val << endl;
        }
        cout << endl;
        node next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
        cout << "After update" << endl;
        if(prev_node == NULL)
        {
            cout << "prev is NULL" << endl; 
        }        
        else
        {
            cout << "prev is " << prev_node->val << endl;
        }
        if(curr_node == NULL)
        {
            cout << "curr is NULL" << endl; 
        }        
        else
        {
            cout << "curr is " << curr_node->val << endl;
        }
        if(next_node == NULL)
        {
            cout << "next is NULL" << endl; 
        }        
        else
        {
            cout << "next is " << next_node->val << endl;
        }
        cout << endl;
    }
    return prev_node;
}

void printList(node head)
{
    node curr_node = head;
    while(curr_node != NULL)
    {
        cout << curr_node->val << " ";
        curr_node = curr_node->next;
    }
    cout << endl;
}

int main()
{  
    node head = createList();
    printList(head);
    cout << "Lets reverse the list now" << endl;
    head = reverseList(head);
    cout << "Printing the reversed list" << endl;
    printList(head);
    return 0;
}