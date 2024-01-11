#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

typedef ListNode* node;

node insertNode(node head, int val)
{
    node new_node = new ListNode(val);
    if(head == NULL)
        return new_node;
    node traverse_node = head;
    while(traverse_node->next != NULL)
    {
        traverse_node = traverse_node->next;
    }
    traverse_node->next = new_node;
    return head;
}

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

node scamSort(node head)
{
    vector<int> nums;
    node traverse_node = head;
    while(traverse_node != NULL)
    {
        nums.push_back(traverse_node->val);
        traverse_node = traverse_node->next;
    }
    sort(nums.begin(), nums.end());
    node new_head = NULL;
    for(int i = 0; i < nums.size(); i++)
    {
        new_head = insertNode(new_head, nums[i]);
    }
    return new_head;
}

int main()
{
    node head = NULL;
    head = insertNode(head, 4);
    head = insertNode(head, 2);
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    printList(head);
    head = scamSort(head);
    // RUNTIME TOO HIGH LES GOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
    printList(head);
    return 0;
}