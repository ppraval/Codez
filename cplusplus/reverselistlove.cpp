#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode* next;
    ListNode(int val) : val(val), next(NULL) {};
};

typedef ListNode* node;

node createList()
{
    node head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    return head;
}

int main()
{
    node head = createList();
    node traverse_node = head;
    while(traverse_node != NULL)
    {
        cout << traverse_node->val << " ";
        traverse_node = traverse_node->next;
    }
    cout << endl;
    node prev_node = NULL;
    traverse_node = head;
    while(traverse_node != NULL)
    {
        node next_node = traverse_node->next;
        traverse_node->next = prev_node;
        prev_node = traverse_node;
        traverse_node = next_node;
    }
    traverse_node = prev_node;
    while(traverse_node != NULL)    
    {
        cout << traverse_node->val << " ";
        traverse_node = traverse_node->next;
    }
    cout << endl;
    return 0;
}