// Code one: This code is almost right, except that there may be duplicates in the result. We need a set to filter it.
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n == 0)
            return res;
        int tmp = 1;
        vector<int> nums;
        while(tmp <= n)
        {
            nums.push_back(tmp);
            tmp++;
        }
        vector<vector<int>> holder;
        helper(holder, nums, 0);
        for(vector<int> a : holder)
        {
            TreeNode* root = new TreeNode(a[0]);
            for(int i = 1; i < a.size(); i++)
                insert(root, a[i]);
            res.push_back(root);
        }
        return res;
    }
    void helper(vector<vector<int>>& holder, vector<int>& nums, int cur)
    {
        if(cur == nums.size())
        {
            holder.push_back(nums);
            return;
        }
        for(int i = cur; i < nums.size(); i++)
        {
            swap(nums[i], nums[cur]);
            helper(holder, nums, cur + 1);
            swap(nums[cur], nums[i]);
        }
    }
    void insert(TreeNode*& root, int tar)
    {
        if(root == NULL)
        {
            root = new TreeNode(tar);
            return;
        }
        if(root->val > tar)
            insert(root->left, tar);
        else
            insert(root->right, tar);
    }
};
