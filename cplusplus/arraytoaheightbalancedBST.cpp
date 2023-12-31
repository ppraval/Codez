#include<bits/stdc++.h>
using namespace std;

TreeNode* solve(vector<int>& nums,int low,int high)
{
    if(low<=high)
    {
        int mid = low + (high - low) / 2;
        TreeNode* root = new TreeNode (nums[mid]);
        root->left = solve(nums, low, mid-1);
        root->right = solve(nums, mid+1, high);
        return root;
    }
    return nullptr;
}
TreeNode* sortedArrayToBST() 
{
    vector<int> nums = {-10,-3,0,5,9};
    return solve(nums, 0, nums.size()-1);
}