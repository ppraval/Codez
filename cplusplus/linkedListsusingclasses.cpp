#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node* next;
        Node(int val) : val(val), next(nullptr) {};   
};

class LinkedList
{
    public:
        Node* insertNode(Node* head, int val)
        {
            Node* new_node = new Node(val);
            if(head == NULL)
                return new_node;
            Node* traverse_node = head;
            while(traverse_node->next != NULL)
            {
                traverse_node = traverse_node->next;
            }
            traverse_node->next = new_node;
            return head;
        }

        void printList(Node* head)
        {
            Node* traverse_node = head;
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
};

int main()
{
    Node* head = NULL;
    LinkedList new_list = LinkedList();
    head = new_list.insertNode(head, 1);
    head = new_list.insertNode(head, 2);
    head = new_list.insertNode(head, 3);
    head = new_list.insertNode(head, 4);
    head = new_list.insertNode(head, 5);
    head = new_list.insertNode(head, 6);
    new_list.printList(head);
}