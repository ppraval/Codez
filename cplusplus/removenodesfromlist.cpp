#include<bits/stdc++.h>
using namespace std;


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef struct ListNode * node;

node createList1()
{
    node head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);
    return head;
}

node createList2()
{
    node head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(1);
    return head;
}

void printList(node head)
{
    while(head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node head = createList2();
    stack<node> s;
    node traverse_node = head;
    while(traverse_node != NULL)
    {
        while(!s.empty() && s.top()->val < traverse_node->val)
        {
            s.pop();
        }
        s.push(traverse_node);
        traverse_node = traverse_node->next;
    }
    node temp = NULL;
    while(!s.empty())
    {
        head = s.top();
        s.pop();
        head->next = temp;
        temp = head;
    }
    printList(head);
    return 0;
}