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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> holder;
        helper(root, sum, res, holder);
        return res;
    }
    void helper(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& holder)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL && root->val == sum)
        {
            holder.push_back(root->val);
            res.push_back(holder);
            holder.pop_back();
            return;
        }
        holder.push_back(root->val);
        helper(root->left, sum - root->val, res, holder);
        helper(root->right, sum - root->val, res, holder);
        holder.pop_back();
    }
};
