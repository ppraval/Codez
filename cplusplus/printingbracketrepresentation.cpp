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
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    return root;
}

void preorderTraversal(node root, string& s)
{
    if(root == NULL)
    {
        return;
    }
    s += "(";
    s += to_string(root->val);
    preorderTraversal(root->left, s);
    preorderTraversal(root->right, s);
    s += ")";
}

int main()
{
    node root = createSampleTree();
    string s = "";
    preorderTraversal(root, s);
    string ans;
    for(int i = 1; i + 1 < s.length(); i++)
    {
        if(s[i] == '(' && s[i + 1] == ')')
        {
            i++;
        }
        ans += s[i];
    }
    cout << ans << endl;
    return 0;
}

