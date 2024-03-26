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
    new_node->left = new TreeNode(8);
    new_node->left->right = new TreeNode(1);
    new_node->left->left = new TreeNode(0);
    new_node->right = new TreeNode(5);
    new_node->right->right = new TreeNode(6);
    return new_node;
}

pair<int, int> preorderTraversal(node root, int sum, int count, int& ans)
{
    if(root == NULL) 
        return {0, 0};

    auto l = preorderTraversal(root->left, sum, count, ans);
    auto r = preorderTraversal(root->right, sum, count, ans);

    sum = l.first + r.first + root->val;
    count = l.second + r.second + 1;

    if(sum / count == root->val) 
        ans++;
    return {sum, count};
}

int main()
{
    node root = createTree1();
    int sum = 0, count = 0, ans = 0;
    preorderTraversal(root, sum, count, ans);
    cout << ans << endl;
    return ans;
}