#include<bits/stdc++.h>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef TreeNode* node;

node createTree()
{
    node new_node = new TreeNode(1);
    new_node->right = new TreeNode(3);
    new_node->left = new TreeNode(2);
    new_node->left->left = new TreeNode(4);
    // new_node->left->right = new TreeNode(5);
    return new_node;
}

// Garbage code
// void inorderTraversal(node root)
// {
//     if(root == NULL)
//         return;
//     inorderTraversal(root->left);
//     cout << root->val << " ";
//     inorderTraversal(root->right);
// }

// int heightOfTree(node root)
// {
//     if(root == NULL)
//         return 0;
//     int left = heightOfTree(root->left);
//     int right = heightOfTree(root->right);
//     return max(left, right) + 1;
// }

// vector<int> rightViewOfTree(node root)
// {
//     vector<int> ans;
//     if(root == NULL)
//         return ans;
//     int left_height = heightOfTree(root->left);
//     int right_height = heightOfTree(root->right);
//     node traverse_node = root;
//     if(right_height >= left_height)
//     {
//         while(traverse_node != NULL)
//         {
//             if(traverse_node->right != NULL)
//             {
//                 ans.push_back(traverse_node->val);
//                 traverse_node = traverse_node->right;
//             }
//             else
//             {
//                 ans.push_back(traverse_node->val);
//                 traverse_node = traverse_node->left;
//             }
//         }
//     }
//     else
//     {
//         while(traverse_node != NULL)
//         {
//             if(traverse_node->right != NULL)
//             {
//                 ans.push_back(traverse_node->val);
//                 traverse_node = traverse_node->right;
//             }
//             else
//             {
//                 ans.push_back(traverse_node->val);
//                 traverse_node = traverse_node->left;
//             }
//         }
//         traverse_node = root;
        
//         for(int i = 0; i < left_height; i++)
//         {
//             if(left_height - right_height == 1)
//             {
//                 if(i >= right_height)
//                 {
//                     if(traverse_node->right != NULL)
//                     {
//                         ans.push_back(traverse_node->val);
//                         traverse_node = traverse_node->right;
//                     }
//                     else
//                     {
//                         ans.push_back(traverse_node->val);
//                         traverse_node = traverse_node->left;
//                     } 
//                 }
//             }
//             else
//             {
//                 if(i > right_height)
//                 {
//                     if(traverse_node->right != NULL)
//                     {
//                         ans.push_back(traverse_node->val);
//                         traverse_node = traverse_node->right;
//                     }
//                     else
//                     {
//                         ans.push_back(traverse_node->val);
//                         traverse_node = traverse_node->left;
//                     } 
//                 }
//             }
//         }
//     }
//     return ans;
// }

void printRightSide(node root , vector<int> & ans , int l)
{
    if(root == NULL)
    {
        return;
    }
    if(l == ans.size())
    {
        ans.push_back(root->val);
    }
    printRightSide(root->right, ans, l+1);
    printRightSide(root->left, ans , l+1);
}

vector<int> rightViewOfTree(node root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;
    queue<node> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        for(int i = 0; i < n; i++)
        {
            node temp = q.front();
            if(i == n - 1)
                ans.push_back(temp->val);
            q.pop();
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
    }
    return ans;
}

int main()
{
    node root = createTree();
    vector<int> ans;
    vector<int> ans1;
    // inorderTraversal(root);
    // cout << endl;
    // cout << heightOfTree(root) << endl;
    // ans = rightViewOfTree(root);
    printRightSide(root, ans, 0);
    for(int x : ans)
        cout << x << " ";
    cout << "\nInterative version" << endl;
    ans1 = rightViewOfTree(root);
    for(int i : ans1)
        cout << i << " ";
    return 0;
}