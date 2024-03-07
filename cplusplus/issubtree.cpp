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

node createTree1()
{
    node root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    return root;
}

node createTree2()
{
    node root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    return root;
}

void inorder(node root, string& s)
{
    if(root == NULL)
    {
        s += "";
        return;
    }
    inorder(root->left, s);
    s += to_string(root->val);
    inorder(root->right, s);
}

void preorder(node root, string& s)
{
    if(root == NULL)
    {
        s += "";
        return;
    }
    s += to_string(root->val);
    preorder(root->left, s);
    preorder(root->right, s);
}

int main()
{
    node tree1 = createTree1();
    node tree2 = createTree2();
    string s1, s2, s3, s4;
    inorder(tree1, s1);
    inorder(tree2, s2);
    preorder(tree1, s3);
    preorder(tree2, s4);
    cout << s1 << endl;
    cout << s2 << endl;
    int pos_1 = s1.find(s2);
    int pos_2 = s3.find(s4);
    cout << s3 << endl;
    cout << s4 << endl;
    if((pos_1 != string::npos) && (pos_2 != string::npos))
    {
        cout << "True" << endl;
        return true;
    }
    cout << "False" << endl;
    return false;
}