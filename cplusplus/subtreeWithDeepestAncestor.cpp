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

typedef TreeNode* node;

node createTree1()
{
    node new_node = new TreeNode(3);
    new_node->left = new TreeNode(5);
    new_node->left->left = new TreeNode(6);
    new_node->left->right = new TreeNode(2);
    new_node->left->right->left = new TreeNode(7);
    new_node->left->right->right = new TreeNode(4);
    new_node->right = new TreeNode(1);
    new_node->right->right = new TreeNode(8);
    new_node->right->left = new TreeNode(0);
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

int maxDepth(node root)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

node LCA(node root, int max_depth, int current_depth)
{
    if(root == NULL || current_depth == max_depth - 1)
    {
        return root;
    }
    node left = LCA(root->left, max_depth, current_depth + 1);
    node right = LCA(root->right, max_depth, current_depth + 1);
    if(left && right)
    {
        return root;
    }
    return left ? left : right;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    node root = createTree1();
    cout << "Inorder Traversal of the tree: ";
    inorderTraversal(root);
    cout << "\n";
    int depth = maxDepth(root);
    cout << "Maximum depth of the tree: " << depth << "\n";
    node deepestAncestor = LCA(root, depth, 0);
    if(deepestAncestor)
    {
        cout << "Deepest ancestor node value: " << deepestAncestor->val << "\n";
    }
    else
    {
        cout << "No deepest ancestor found.\n";
    }
    return 0;
}