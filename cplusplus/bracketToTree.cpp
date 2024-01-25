#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
};

typedef TreeNode* node;

node treeFromParenthesis(string s, int& i)
{
    if(s.length() == 0 || i >= s.length())
        return NULL;
    int val = 0;
    while(s[i] != '(' && s[i] != ')' && i < s.length())
    {
        int num = s[i] - '0';
        val = val * 10 + num;
        i++;
    }
    node root = NULL;
    if(val > 0)
        root = new TreeNode(val);
    
    if(i < s.length() && s[i] == '(')
    {
        i++;
        root->left = treeFromParenthesis(s, i);
    }
    if(i < s.length() && s[i] == ')')
    {
        i++;
        return root;
    }

    if(i < s.length() && s[i] == '(')
    {
        i++;
        root->right = treeFromParenthesis(s, i);
    }
    if(i < s.length() && s[i] == ')')
    {
        i++;
        return root;
    }
    return root;
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
    string s = "7(5()())(9()())";
    int i = 0;
    node root = NULL;
    root = treeFromParenthesis(s, i);
    inorderTraversal(root);
    return 0;
}