#include<bits/stdc++.h>
using namespace std;

// incomplete solution and not a correct one;
// bool isValidBST(TreeNode* root) {
//         if(root->right == NULL && root->left == NULL)
//         {
//             return 1;
//         }
//         if(root->right == NULL)
//         {
//             if(root->left->val < root->val)
//                 return 1;
//             else
//                 return 0;
//         }
//         if(root->left == NULL)
//         {
//             if(root->right->val > root->val)
//                 return 1;
//             else
//                 return 0;
//         }
//         if(root->right->val > root->val && root->left->val < root->val)
//         {
//             return 1;
//         }
//         else
//         {
//             return 0;
//         }
//         isValidBST(root->left);
//         isValidBST(root->right);
//     }

//Best Code
void inorderArr(TreeNode* root, vector<int> &nums)
{
    if(root == NULL)
    {
        return;
    }
    inorderArr(root->left, nums);
    nums.push_back(root->val);
    inorderArr(root->right, nums);
}
bool isValidBST(TreeNode* root) {
    vector<int> nums;
    inorderArr(root, nums);
    for(int i = 0; i + 1 < nums.size(); i++)
    {
        if(!(nums[i] < nums[i + 1]))
            return 0;
    }
    return 1;
}
