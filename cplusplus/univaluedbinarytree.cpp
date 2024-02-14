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
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);    
    return root;
}

void inorderTraversal(node root, vector<int>& res)
{
    if(root == NULL)
        return;
    inorderTraversal(root->left, res);
    res.push_back(root->val);
    inorderTraversal(root->right, res);
}

int main()
{
    node root = createSampleTree();
    vector<int> res;
    inorderTraversal(root, res);
    for(int i = 0; i + 1 < res.size(); i++)
    {
        if(res[i] != res[i + 1])
        {
            cout << "False" << endl;
            return 0;
        }
    }
    cout << "True" << endl;
    return 0;
}

