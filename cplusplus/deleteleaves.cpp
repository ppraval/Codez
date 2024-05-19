#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef TreeNode* node;

node createTree()
{
    node root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    return root;
}

void inorder(node root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

node preorder(node root, node parent, int val)
{
    if(root == NULL)
        return root;
    root->left = preorder(root->left, root, val);
    root->right = preorder(root->right, root, val);
    if(root->left == NULL && root->right == NULL && root->val == val)
    {
        if(parent != NULL)
            delete root;
        return NULL;
    }
    return root;
}

int main()
{
    node root = createTree();
    inorder(root);
    cout << endl;
    int val = 2;
    root = preorder(root, NULL, val);
    inorder(root);
    cout << endl;
    return 0;
}