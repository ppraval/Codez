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
    node new_node = new TreeNode(3);
    new_node->left = new TreeNode(1);
    new_node->left->left = new TreeNode(3);
    new_node->right = new TreeNode(4);
    new_node->right->right = new TreeNode(5);
    new_node->right->left = new TreeNode(1);
    return new_node;
}

void inorderTraversal(node root)
{
    if(root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(node root, int& count, int max)
{
    if(root == NULL)
    {
        return;
    }
    if(root->val >= max)
    {
        count++;
        max = root->val;
    }
    preorderTraversal(root->left, count, max);
    preorderTraversal(root->right, count, max);
}

int main()
{
    node root = createTree1();
    int count = 0;
    preorderTraversal(root, count, root->val);
    cout << count << endl;
    return 0;
}