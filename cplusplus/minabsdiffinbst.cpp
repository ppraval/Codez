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

typedef TreeNode *node;

node createTree1()
{
    node new_node = new TreeNode(4);
    new_node->left = new TreeNode(2);
    new_node->left->right = new TreeNode(3);
    new_node->left->left = new TreeNode(1);
    new_node->right = new TreeNode(5);
    return new_node;
}

void inorderTraversal(node root, vector<int>& inorder)
{
    if(root == NULL)
    {
        return;
    }
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right, inorder);
}

int main()
{
    node root = createTree1();
    vector<int> inorder;
    inorderTraversal(root, inorder);
    int diff = INT_MAX;
    for(int i = 0; i < inorder.size() - 1; i++)
    {
        diff = min(diff, abs(inorder[i] - inorder[i + 1]));
    }
    cout << diff;
    return diff; 
}