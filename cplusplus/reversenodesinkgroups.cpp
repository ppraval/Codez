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

node createlist()
{
    node head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    return head;
}

void printlist(node head)
{
    node traverse_node = head;
    while(traverse_node != NULL)
    {
        cout << traverse_node->val << " ";
        traverse_node = traverse_node->next;
    }
    cout << endl;
}

node reverseList(node head)
{
    node curr = head;
    node prev = NULL;
    while(curr != NULL)
    {
        node next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

node getKthNode(node head, int k)
{
    k--;
    while(head != NULL && k > 0)
    {
        head = head->next;
        k--;
    }
    return head;
}

node reverseKpairs(node head, int k)
{
    node curr = head;
    node prev = NULL;
    while(curr != NULL)
    {
        node node_k = getKthNode(curr, k);
        if(node_k == NULL)
        {
            if(prev != NULL)
                prev->next = curr;
            break;
        }
        node next = node_k->next;
        node_k->next = NULL;
        reverseList(curr);
        if(curr == head)
        {
            head = node_k;
        }
        else
        {
            prev->next = node_k;
        }
        prev = curr;
        curr = next;
    }
    return head;
}

int main()
{
    node head = createlist();
    head = reverseKpairs(head, 2);
    printlist(head);
    return 0;
}