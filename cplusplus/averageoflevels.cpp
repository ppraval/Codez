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
  root->left = new TreeNode(20);
  root->left->left = new TreeNode(15);
  root->left->right = new TreeNode(7);
  root->right = new TreeNode(9);
  return root;
}

vector<double> averagelevelorderTraversal(node root)
{
    vector<double> ans;
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
        double sum = 0.0;        
        for(int i = 0; i < n; i++)
        {
            node temp = q.front();
            sum += 1.0 * (temp->val);
            q.pop();
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
            level.push_back(temp->val);
        }
        sum = (sum) / (1.0 * n);
        ans.push_back(sum);
    }
    return ans;
}

int main()
{
    node root = createSampleTree();
    vector<double> ans;
    ans = averagelevelorderTraversal(root);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }    
    return 0;
}