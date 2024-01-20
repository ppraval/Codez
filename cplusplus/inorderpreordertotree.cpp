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

node buildTree(vector<int>& inorder, vector<int>& preorder, int& root, int left, int right, unordered_map<int, int>& mp)
{
    if(left > right)
    {
        return NULL;
    }
    int i = mp[preorder[root]];
    root++;
    node new_node = new TreeNode(inorder[i]);
    new_node->left = buildTree(inorder, preorder, root, left, i - 1, mp);
    new_node->right = buildTree(inorder,  preorder, root, i + 1, right, mp);
    return new_node;
}

void preorderTraversal(node root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    int root_index = 0;
    unordered_map<int, int> mp;
    int pre_index = 0;
    for(int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }

    node root = buildTree(inorder, preorder, root_index, 0, inorder.size() - 1, mp);
    preorderTraversal(root);
    return 0;
}