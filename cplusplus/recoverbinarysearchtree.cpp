#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
};

typedef TreeNode *node;

node createSampleTree()
{
    node root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    return root;
}

void inorderTraversal(node root, node& first, node& second, node& prev) 
{
    if(root == NULL) 
        return;
    inorderTraversal(root->left, first, second, prev);
    if(first == NULL && root->val < prev->val)
        first = prev;
    if(first != NULL && root->val < prev->val)
        second = root;
    prev = root;
    inorderTraversal(root->right, first, second, prev);
}

void inorderPrint(node root)
{
    if(root == NULL)
        return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}


int main()
{
    node root = createSampleTree();
    node prev = new TreeNode(INT_MIN);
    node first = NULL;
    node second = NULL;
    inorderPrint(root);
    cout << endl;
    inorderTraversal(root, first, second, prev);
    swap(first->val, second->val);
    inorderPrint(root);
    return 0;
}
