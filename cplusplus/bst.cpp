#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int val;
        node* right;
        node* left;

        node(int val)
        {
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};

class bst
{
    public:
        node* root;
    
    bst()
    {
        this->root = NULL;
    }
    
};

node* changeNode(node* node, int val)
{
    node->val = val;
    return node;
}

int main()
{
    node* node1 = new node(5);
    cout << node1->val << endl;
    node* new_node = changeNode(node1, 234);
    cout << new_node->val << endl;
    return 0;
}