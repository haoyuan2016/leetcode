/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Solution one
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
    vector<int> res;
    helper(root, res);
    return res[k - 1];
    }
    void helper(TreeNode* root, vector<int>& res)
    {
        if(root == NULL) return;
        if(root->left) helper(root->left, res);
            res.push_back(root->val);
        if(root->right) helper(root->right, res);
    }
};
// Solution two
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
    int kthSmallest(TreeNode* root, int k) {
    int res;
    int cur = k;
    helper(root, cur, res);
    return res;
    }
    void helper(TreeNode* root, int& cur, int& res)
    {
        if(root == NULL) return;
        if(root->left) helper(root->left, cur, res);
        cur--;
        if(cur == 0)
            res = root->val;
        if(root->right) helper(root->right, cur, res);
    }
};
