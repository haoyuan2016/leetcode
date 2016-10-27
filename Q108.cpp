/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        int n = nums.size();
        return helper(nums, 0, n - 1);
    }
    TreeNode* helper(vector<int> nums, int a, int b)
    {
        if(a > b) return NULL;
        TreeNode* root = new TreeNode(nums[(a + b) / 2]);
        root->left = helper(nums, a, (a + b) / 2 - 1);
        root->right = helper(nums, (a + b) / 2 + 1, b);
        return root;
    }
};
