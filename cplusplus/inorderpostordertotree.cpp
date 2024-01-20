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

node buildTree(vector<int>& inorder, vector<int>& postorder, int& root, int left, int right, unordered_map<int, int>& mp)
{
    if(left > right)
    {
        return NULL;
    }
    int i = mp[postorder[root]];
    root--;
    node new_node = new TreeNode(inorder[i]);
    new_node->right = buildTree(inorder,  postorder, root, i + 1, right, mp);
    new_node->left = buildTree(inorder, postorder, root, left, i - 1, mp);
    return new_node;
}

void postorderTraversal(node root)
{
    if(root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}

int main()
{
    vector<int> postorder = {3,9,20,15,7};
    vector<int> inorder = {9,15,7,20,3};
    int root_index = inorder.size() - 1;
    unordered_map<int, int> mp;
    int post_index = 0;
    for(int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    node root = buildTree(inorder, postorder, root_index, 0, inorder.size() - 1, mp);
    cout << "Do we run here?" << endl;
    postorderTraversal(root);
    cout << "or here?" << endl;
    return 0;
}