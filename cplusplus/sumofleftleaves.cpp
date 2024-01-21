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
    node root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
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

void traverseSum(node root, int& sum, int& flag)
{
    if(root == NULL)
    {
        return;
    }
    if(root->left == NULL && root->right == NULL && flag == 1)
    {
        sum += root->val;
    }
    flag = 1;
    traverseSum(root->left, sum, flag);
    flag = 0;
    traverseSum(root->right, sum, flag);
}

int main()
{
    node root = createSampleTree();
    int sum = 0;
    int flag = 0;
    traverseSum(root, sum, flag);
    cout << sum;
    return 0;
}