#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    int height;
    struct TreeNode* right;
    struct TreeNode* left;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), height(1) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef TreeNode *node;

int height(node root)
{
    if(root == NULL)
        return 0;
    return root->height;
}

int getBalance(node root)
{
    if(root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

node leftRotate(node x)
{
    node y = x->right;
    node t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

node rightRotate(node y)
{
    node x = y->left;
    node t2 = x->right;

    x->right = y;
    y->left = t2;
    
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return x;
}

node insertAVL(node root, int val)
{
    node new_node = new TreeNode(val);
    if(root == NULL)
        return new_node;
    if(root->val > val)
        root->left = insertAVL(root->left, val);
    else if(root->val < val)
        root->right = insertAVL(root->right, val);
    else
        return root;
    
    root->height = max(height(root->left), height(root->right)) + 1;

    int bf = getBalance(root);

    if(bf > 1 && val < root->left->val)
    {
        return rightRotate(root);
    }
    if(bf < -1 && val > root->right->val)
    {
        return leftRotate(root);
    }
    if(bf > 1 && val > root->left->val)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(bf < -1 && val < root->right->val)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inorderTraversal(node root)
{
    if(root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main()
{
    node root = NULL;
    root = insertAVL(root, 10);
    root = insertAVL(root, 20); 
    root = insertAVL(root, 30); 
    root = insertAVL(root, 40); 
    root = insertAVL(root, 50);  
    root = insertAVL(root, 25);
    inorderTraversal(root);
    return 0;
}