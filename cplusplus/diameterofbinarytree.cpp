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
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
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

int diameterOfTree(node root, int& dia)
{
    if(root == NULL)
    {
        return 0;
    }
    int left = diameterOfTree(root->left, dia);
    int right = diameterOfTree(root->right, dia);
    dia = max(dia, left + right);
    return max(left, right) + 1;
}

int main()
{
    node root = createSampleTree();
    int d = 0;
    diameterOfTree(root, d);
    cout << d << endl;
    return 0;
}