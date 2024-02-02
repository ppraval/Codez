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
    node new_node = new TreeNode(1);
    new_node->left = new TreeNode(2);
    new_node->right = new TreeNode(3);
    return new_node;
}

node createTree2()
{
    node new_tree = new TreeNode(4);
    new_tree->left = new TreeNode(2);
    new_tree->right = new TreeNode(9);
    new_tree->right->right = new TreeNode(7);
    new_tree->left->left = new TreeNode(3);
    new_tree->left->right = new TreeNode(5);
    return new_tree;
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

int findTilt(node root, int& sum)
{
    if(root == NULL) 
        return 0;
    int left_sum = findTilt(root->left, sum);     
    int right_sum = findTilt(root->right, sum);             
    sum += abs(left_sum - right_sum);             
    return left_sum + right_sum + root->val;
}

int main()
{
    node root = createTree2();
    inorderTraversal(root);
    cout << endl;
    int sum = 0;
    findTilt(root, sum);
    cout << sum;
    cout << endl;
    return 0;
}