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
    node root = new TreeNode(8);
    root->right = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(4);
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

void maxDiffPostOrder(node root, int max_val, int min_val, int& max_diff)
{
    if(root == NULL)
        return;
    max_val = max(max_val, root->val);
    min_val = min(min_val, root->val);
    max_diff = max(max_diff, max_val - min_val);
    maxDiffPostOrder(root->left, max_val, min_val, max_diff);
    maxDiffPostOrder(root->right, max_val, min_val, max_diff);
}

int main()
{
    node root = createTree();
    int max_diff = 0;
    maxDiffPostOrder(root, root->val, root->val, max_diff);
    cout << max_diff << endl;
    inorder(root);
    return 0;
}