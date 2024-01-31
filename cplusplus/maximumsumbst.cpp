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
    node root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(5);
    root->right->left = new TreeNode(2);
    root->right->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(4);
    root->left = new TreeNode(4);
    root->left->right = new TreeNode(4);
    root->left->left = new TreeNode(2);
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

int summingUpBst(node root, int& max_val, int& min_val, int& max_sum)
{
    if(root == NULL)
    {
        return 0;
    }

    int left_max = INT_MIN, left_min = INT_MAX;
    int right_max = INT_MIN, right_min = INT_MAX;

    int left_sum = summingUpBst(root->left, left_max, left_min, max_sum);
    int right_sum = summingUpBst(root->right, right_max, right_min, max_sum);

    int val = root->val + left_sum + right_sum; 
    
    if(left_max < root->val && right_min > root->val)
    {
        max_sum = max(max_sum, val);
        max_val = max(root->val, right_max);
        min_val = min(root->val, left_min);
    }
    else
    {
        max_val = INT_MAX;
        min_val = INT_MIN;
    }
    return val;
}

int main()
{
    node root = createTree1();
    inorderTraversal(root);
    cout << endl;
    int max_sum = 0;
    int max_val = INT_MAX;
    int min_val = INT_MIN;
    summingUpBst(root, max_val, min_val, max_sum);
    cout << max_sum << endl;
    return 0;
}