// solution one, time out
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(isFind(root->left, p) && isFind(root->left, q))
            return lowestCommonAncestor(root->left, p, q);
        else if(isFind(root->right, p) && isFind(root->right, q))
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
    bool isFind(TreeNode* root, TreeNode* p)
    {
        if(p == NULL) return true;
        if(root == NULL) return false;
        if(p == root) return true;
        return isFind(root->left, p) || isFind(root->right, p);
    }
};
// Solution two, so beautiful O(N) solution, see https://discuss.leetcode.com/topic/18566/my-java-solution-which-is-easy-to-understand
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != NULL && right != NULL) return root;
        if(left != NULL) return left;
        else return right;
    }
};
