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
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    return root;
}

vector<int> largestValues(node root)
{
    vector<int> res;
    if(root == NULL)
    {
        return res;
    }
    queue<node> q;
    q.push(root);
    while(!q.empty())
    {
        int max_element = INT_MIN;
        int n = q.size();
        for(int i = 0; i < n; i++)
        {
            node temp = q.front();
            q.pop();
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
            max_element = max(temp->val, max_element);
        }
        res.push_back(max_element);
    }
    return res;
}

int main()
{
    node root = createSampleTree();
    vector<int> res = largestValues(root);
    for(auto x : res)
        cout << x << " ";
    return 0;
}