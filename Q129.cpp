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
    int sumNumbers(TreeNode* root) {
        int total = 0;
        helper(root, 0, total);
        return total;
    }
    void helper(TreeNode* root, int cur, int& total)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL)
        {
            total += root->val + 10 * cur;
            return;
        }
        helper(root->left, root->val + 10 * cur, total);
        helper(root->right, root->val + 10 * cur, total);
    }
};

// Solution two:
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
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
    int helper(TreeNode* root, int cur)
    {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return root->val + 10 * cur;
        return helper(root->left, 10 * cur + root->val) + helper(root->right, 10 * cur + root->val);
    }
};
