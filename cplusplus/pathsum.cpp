#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

typedef struct TreeNode *node;

node createTree1()
{
    node root = new TreeNode(5);
    root->right = new TreeNode(8);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    return root;
}

node createTree2()
{
    node root = new TreeNode(1);
    root->right = new TreeNode(2);
    return root;
}

void inorderTraversal(node root, int targetsum, int sum, int& flag)
{
    if(root == NULL)
    {
        if(targetsum == sum)
        {
            flag = 1;
        }
        return;
    }
    sum += root->val;
    inorderTraversal(root->left, targetsum, sum, flag);
    cout << root->val << " ";
    inorderTraversal(root->right, targetsum, sum, flag);
}

int main()
{
    node root = createTree2();
    int flag = 0;
    int targetsum = 1;
    inorderTraversal(root, targetsum, 0, flag);
    cout << endl;
    if(flag == 1)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}