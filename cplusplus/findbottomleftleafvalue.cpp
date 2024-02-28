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

int main()
{
    node root = createTree1();
    int last = 0;
    queue<node> q;
    q.push(root);
    while(!q.empty())
    {
        int count = q.size();
        for(int i = 0; i < count; i++)
        {
            TreeNode* curr = q.front();
            q.pop();
            if(i == 0)
                last = curr->val;
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
    cout << last;
    return last;
}