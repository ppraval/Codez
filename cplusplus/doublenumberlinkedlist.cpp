#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef ListNode* node;

node createList()
{
    node head = new ListNode(1);
    head->next = new ListNode(8);
    head->next->next = new ListNode(9);
    return head;
}

void printList(node head)
{
    if(head == NULL)
        return;
    node traverse_node = head;
    while(traverse_node != NULL)
    {
        cout << traverse_node->val << " ";
        traverse_node = traverse_node->next;
    }
    cout << endl;
}
 
int main()
{
    node head = createList();
    // printList(head);
    if(head == NULL)
        return 0;
    node traverse_node = head;
    int val = 0;
    while(traverse_node != NULL)
    {
        val = val * 10 + traverse_node->val;
        traverse_node = traverse_node->next;
    }
    
    val += val;
    cout << val << endl;
    string double_val = to_string(val);
    cout << "This is a string " << double_val << endl;
    node new_head = new ListNode(double_val[0] - '0');
    traverse_node = new_head;
    for(int i = 1; i < double_val.length(); i++)
    {
        traverse_node->next = new ListNode(double_val[i] - '0');
        traverse_node = traverse_node->next;
    }
    printList(new_head);
    return 0;
}