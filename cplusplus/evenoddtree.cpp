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

node createTree()
{
    node new_node = new TreeNode(1);
    new_node->left = new TreeNode(10);
    new_node->left->left = new TreeNode(3);
    new_node->left->left->left = new TreeNode(12);
    new_node->left->left->right = new TreeNode(8);
    new_node->right = new TreeNode(4);
    new_node->right->left = new TreeNode(7);
    new_node->right->left->left = new TreeNode(6);
    new_node->right->right = new TreeNode(9);
    new_node->right->right->right = new TreeNode(2);
    return new_node;
}

void inorderTraversal(node root)
{
    if(root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main()
{
    node root = createTree();

    if(root==NULL)
    {
        cout << "False";
        return true;
    }
    queue<node> q;
    bool flag = true;
    
    q.push(root);
    while(!q.empty())
    {
        int l = q.size();
        int prev = INT_MAX; 
        if(flag == 1)
            prev = INT_MIN;
        for(int i = 0; i < l; i++)
        {
            node temp = q.front();
            q.pop();  
            if(flag == 1)
            {
                if(temp->val % 2 == 0 || temp->val <=  prev)
                {
                    cout << "False";
                    return false;
                }
            }
            else
            {
                if(temp->val % 2 != 0  || temp->val >= prev)
                {
                    cout << "False";
                    return false;
                }
            }
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
            prev = temp->val;
        }
        flag = !flag;
    }
    cout << "True";
    return true;
}