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
  node root = new TreeNode(3);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  root->left = new TreeNode(9);
  return root;
}

vector<vector<int>> zigzagTraversal(node root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<node> q;
    q.push(root);
    int flag = 1;
    while(!q.empty())
    {
        vector<int> level;
        int n = q.size();
        for(int i = 0; i < n; i++)
        {
            node temp = q.front();
            level.push_back(temp->val);
            q.pop();
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
        if(flag == 0)
            flag = 1;
        else
            flag = 0;
        if(flag == 1)
            reverse(level.begin(), level.end());
        ans.push_back(level);
    }
    return ans;
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

int main()
{
    node root = createSampleTree();
    vector<vector<int>> ans;
    ans = zigzagTraversal(root);
    inorderTraversal(root);
    cout << endl;
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++) 
        {
            cout << ans[i][j] << " ";
        }
    }
    return 0;
}