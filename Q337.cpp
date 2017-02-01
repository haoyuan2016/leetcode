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
    int rob(TreeNode* root) {
        return getValue(root);
    }
    int getValue(TreeNode* root)
    {
        if(root == NULL) return 0;
        else if(root->left == NULL && root->right == NULL) return root->val;
        else
        {
            int notRob = getValue(root->left) + getValue(root->right);
            int doRob = root->val;
            if(root->left && root->left->left)
                doRob += getValue(root->left->left);
            if(root->left && root->left->right)
                doRob += getValue(root->left->right);
            if(root->right && root->right->left)
                doRob += getValue(root->right->left);
            if(root->right && root->right->right)
                doRob += getValue(root->right->right);
            return max(notRob, doRob);
        }
    }
};
