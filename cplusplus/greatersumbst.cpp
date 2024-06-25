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

typedef TreeNode *node;

node createTree1()
{
    node new_node = new TreeNode(4);
    new_node->left = new TreeNode(1);
    new_node->left->left = new TreeNode(0);
    new_node->left->right = new TreeNode(2);
    new_node->left->right->right = new TreeNode(3);
    new_node->right = new TreeNode(6);
    new_node->right->right = new TreeNode(7);
    new_node->right->right->right = new TreeNode(8);
    new_node->right->left = new TreeNode(5);
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

void inorderChange(node root, unordered_map<int, int> mp)
{
    if(root == NULL)
    {
        return;
    }
    inorderChange(root->left, mp);
    root->val = mp[root->val];
    inorderChange(root->right, mp);
}

int main()
{
    node root = createTree1();
    vector<int> inorder;
    unordered_map<int, int> mp;
    inorderTraversal(root, inorder);
    for(int i : inorder)
        cout << i << " ";
    cout << endl;
    int sum = accumulate(inorder.begin(), inorder.end(), 0);
    for(int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = sum;
        sum -= inorder[i];
    }
    for(auto x : mp)
        cout << x.first << "-" << x.second << endl;
    inorderChange(root, mp);
    // inorderTraversal(root, inorder);
    // for(int i : inorder)
    //     cout << i << " ";
    return 0;
}