#include<bits/stdc++.h>
using namespace std;

struct TreeNode 
{
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
    node root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

void inorder(node root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

node buildTree(vector<int>& postorder, vector<int>& preorder, int& postIndex, int preStart, int preEnd)
{
    if(preStart > preEnd || postIndex < 0)
        return NULL;

    node root = new TreeNode(preorder[preStart]);
    postIndex--;

    if(preStart == preEnd)
        return root;

    int index;
    for(index = preStart + 1; index <= preEnd; index++)
    {
        if(preorder[index] == postorder[postIndex])
            break;
    }

    root->left = buildTree(postorder, preorder, postIndex, preStart + 1, index - 1);
    root->right = buildTree(postorder, preorder, postIndex, index, preEnd);
    
    return root;
}

int main()
{
    // node root = createTree();
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    int n = postorder.size();
    int postIndex = n - 1;
    node root = buildTree(postorder, preorder, postIndex, 0, n - 1);
    cout << "Inorder traversal of the constructed tree: ";
    inorder(root);
    return 0;
}