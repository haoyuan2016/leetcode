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
// Solution two
// Note that learn to construct a vector from an existing vector. Note that newVec(oldVec.begin(), oldVec.end());
// Two things, the first is oldVec.end() must be added, the second is oldVec.end() is not included.
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int> nums) {
        if(nums.empty()) return NULL;
        int n = nums.size();
        int index = n / 2;
        TreeNode* root = new TreeNode(nums[index]);
        vector<int> leftVector(nums.begin(), nums.begin() + index);
        vector<int> rightVector(nums.begin() + index + 1, nums.end());
        root->left = sortedArrayToBST(leftVector);
        root->right = sortedArrayToBST(rightVector);
        return root;
    }
};
