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
    // root->right->left = new TreeNode(15);
    root->left->right = new TreeNode(4);
    return root;
}

void inorderTraversal(node root)
{
    if(root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

void fillArray(node root, vector<vector<string>>& ans, int& height, int row, int col)
{
    if(root == NULL)
    {
        return;
    }
    ans[row][col] = to_string(root->val);
    int l = col - pow(2, height - row - 1);
    int r = col + pow(2, height - row - 1);
    fillArray(root->left, ans, height, row + 1, l);
    fillArray(root->left, ans, height, row + 1, r);
}

int heightOfTree(node root)
{
    if(root == NULL)
    {
        return 0;
    }
    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    return max(left, right) + 1;
}


// does not work properly AHAHHAHAHAHAH


int main()
{
    node root = createSampleTree();
    inorderTraversal(root);
    int height = heightOfTree(root) - 1;
    cout << endl << height << endl;
    int width = pow(2, height + 1) -  1;
    vector<vector<string>> ans(height + 1, vector<string>(width, ""));
    int row = 0;
    int col = (width - 1) / 2;
    fillArray(root, ans, height, row, col);
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << "_";
        }
        cout << endl;
    }
    return 0;
}