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
    node new_node = new TreeNode(2);
    new_node->left = new TreeNode(3);
    new_node->left->left = new TreeNode(3);
    new_node->left->right = new TreeNode(1);
    new_node->right = new TreeNode(1);
    new_node->right->right = new TreeNode(1);
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

int main()
{
    node root = createTree1();
    inorderTraversal(root);
    return 0;
}