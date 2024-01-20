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
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right = new TreeNode(3);
  return root;
}

vector<vector<int>> levelorderTraversal(node root)
{
    vector<vector<int>> ans;
    if(root == NULL)
    {
        return ans;
    }
    queue<node> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> level;
        int n = q.size();
        for(int i = 0; i < n; i++)
        {
            node temp = q.front();
            q.pop();
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
            level.push_back(temp->val);
        }
        ans.push_back(level);
    }
    return ans;
}

int main()
{
    node root = createSampleTree();
    vector<vector<int>> ans;
    ans = levelorderTraversal(root);
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
    }    
    return 0;
}