#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode* right;
    struct TreeNode* left;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef TreeNode*node;

node createTree1()
{
    node new_node = new TreeNode(1);
    new_node->left = new TreeNode(2);
    new_node->left->left = new TreeNode(3);
    new_node->left->right = new TreeNode(4);
    new_node->right = new TreeNode(5);
    new_node->right->right = new TreeNode(6);
    return new_node;
}

void inorderTraversal(node root)
{
    if(!root)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

void flatten(node root, node& prev)
{
    if(!root)
        return;
    flatten(root->right, prev);
    flatten(root->left, prev);
    root->right = prev;
    root->left = NULL;
    prev = root;
}

int main()
{
    node root = createTree1();
    inorderTraversal(root);
    cout << endl;
    node prev = NULL;
    flatten(root, prev);
    inorderTraversal(root);
    return 0;
}