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
    return root;
}

int postorder(node root, int &max_val)
{
    if(root == NULL)
        return 0;
    int left = 0 + max(0, postorder(root->left, max_val));
    int right = 0 + max(0, postorder(root->right, max_val));
    max_val = max(max_val, left + right + root->val);
    return max(left, right) + root->val;
}

int main()
{
    int max_val = INT_MIN;
    node root = createSampleTree();
    postorder(root, max_val);
    cout << max_val << endl;
    return 0;
}