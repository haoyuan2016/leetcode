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
    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
    }
    bool isBST(TreeNode* root, long smallest, long largest)
    {
        if(root == NULL) return true;
        if(root->val <= smallest) return false;
        if(root->val >= largest) return false;
        return isBST(root->left, smallest, root->val) && isBST(root->right, root->val, largest);
    }
};
