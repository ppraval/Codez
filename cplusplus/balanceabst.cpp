#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    int height;
    struct TreeNode* right;
    struct TreeNode* left;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef TreeNode *node;

node createTree()
{
    node new_node = new TreeNode(1);
    new_node->right = new TreeNode(2);
    new_node->right->right = new TreeNode(3);
    new_node->right->right->right = new TreeNode(4);
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

void postorder(node root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    cout << root->val << " ";
    postorder(root->right);
}


int main()
{
    node root = createTree();   
    vector<int> inorder;
    inorderTraversal(root, inorder);
    node new_root = NULL;
    for(int i : inorder)
    {
        new_root = insertAVL(new_root, i);
    }
    vector<int> temp;
    inorderTraversal(new_root, temp);
    for(int i : temp)
        cout << i << " ";
    cout << endl;
    postorder(new_root);
    return 0;
}