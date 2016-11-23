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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return vector<string>{};
        vector<string> res;
        if(root->left == NULL && root->right == NULL)
        {
            res.push_back(to_string(root->val));
            return res;
        }
        vector<string> l = binaryTreePaths(root->left);
        vector<string> r = binaryTreePaths(root->right);
        string tmp;
        for(auto a : l)
        {
            tmp = to_string(root->val) + "->" + a;
            res.push_back(tmp);
        }
        for(auto b : r)
        {
            tmp = to_string(root->val) + "->" + b;
            res.push_back(tmp);
        }
        return res;
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL) return res;
        helper(root, res, to_string(root->val));
        return res;
    }
    void helper(TreeNode* root, vector<string>& res, string t)
    {
        if(root->left == NULL && root->right == NULL)
        {
            res.push_back(t);
            return;
        }
        if(root->left) helper(root->left, res, t + "->" + to_string(root->left->val));
        if(root->right) helper(root->right, res, t + "->" + to_string(root->right->val));
    }
};
