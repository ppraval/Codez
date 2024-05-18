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
    node root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);
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

int preorder(node root, node parent)
{
    if(root == NULL)
    {
        return 0;
    }
    int left = preorder(root->left, root);
    int right = preorder(root->right, root);
    int val = root->val - 1;
    int moves = right + left;
    if(parent != NULL)
    {
        parent->val += val;
    }
    moves += abs(val);
    return moves;
}

int main()
{
    node root = createTree();
    inorder(root);
    int ans = preorder(root, NULL);
    cout << endl << ans << endl;
    inorder(root);
    return 0;
}