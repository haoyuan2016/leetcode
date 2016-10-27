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
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        if(abs(depth(root->left) - depth(root->right)) <= 1)
            return isBalanced(root->left) && isBalanced(root->right);
        return false;
    }
    int depth(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
};
