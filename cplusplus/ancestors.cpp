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
    node new_node = new TreeNode(7);
    new_node->left = new TreeNode(5);
    new_node->left->left = new TreeNode(2);
    new_node->left->right = new TreeNode(6);
    new_node->right = new TreeNode(9);
    new_node->right->right = new TreeNode(10);
    new_node->right->left = new TreeNode(8);
    return new_node;
}

node createTree2()
{
    node new_node = new TreeNode(8);
    new_node->left = new TreeNode(5);
    new_node->left->right = new TreeNode(6);
    new_node->right = new TreeNode(10);
    new_node->right->right = new TreeNode(11);
    return new_node;
}

void inorderTraversal(node root)
{
    if(root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

void ancestorsOfNode(node root, int val, int &flag)
{
    if(root == NULL || flag == 1)
    {
        return;
    }
    ancestorsOfNode(root->left, val, flag);
    ancestorsOfNode(root->right, val, flag);
    if(val == root->val || flag == 1)
    {
        cout << root->val << " ";
        flag = 1;
        return;
    }
}


int main()
{
    int flag = 0;
    node root = createTree2();
    inorderTraversal(root);
    cout << endl;
    ancestorsOfNode(root, 6, flag);
    return 0;
}