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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty() || postorder.empty() || inorder.size() != postorder.size()) return NULL;
        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode* helper(vector<int> inorder, vector<int> postorder, int a, int b, int c, int d)
    {
        if(a > b || c > d) return NULL;
        TreeNode* root = new TreeNode(postorder[d]);
        int i = a;
        while(inorder[i] != postorder[d])
            i++;
        root->left = helper(inorder, postorder, a, i - 1, c, c + i - 1 - a);
        root->right = helper(inorder, postorder, i + 1, b, c + i - a, d - 1);
        return root;
    }
};
