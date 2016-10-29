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
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        if(root->left) flatten(root->left);
        if(root->right) flatten(root->right);
        if(root->left == NULL && root->right == NULL) return;
        if(root->left != NULL && root->right == NULL)
        {
            root->right = root->left;
            root->left = NULL;
        }
        else if(root->left != NULL && root->right != NULL)
        {
            TreeNode* tmp = root->right;
            root->right = root->left;
            root->left = NULL;
            TreeNode* tmp1 = root->right;
            while(tmp1->right) tmp1 = tmp1->right;
            tmp1->right = tmp;
        }
    }
};
