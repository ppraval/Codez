#include<bits/stdc++.h>
using namespace std;

 void inorder(TreeNode* root, vector<int>& nums)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
}

int main()
{
    vector<int> nums;
    int low, high;
    inorder(root, nums);
    int res = 0;
    for(int x : nums)
    {
        if( x >= low && x <= high)
        {
            res += x;
        }
    }
    return res;
    return 0;
}