// So hard to find the index in recursions.. 
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size()) return NULL;
        return helper(preorder, inorder, 0, (int)preorder.size() - 1, 0, (int)inorder.size() - 1);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int a, int b, int c, int d) {
        if(a > b || c > d) return NULL;
        TreeNode* root = new TreeNode(preorder[a]);
        int index = 0;
        for(int i = c; i <= d; i++)
        {
            if(inorder[i] == preorder[a])
                break;
            index++;
        }
        root->left = helper(preorder, inorder, a + 1, a + index, c, c + index - 1);
        root->right = helper(preorder, inorder, a + index + 1, b, c + index + 1, d);
        return root;
    }
};
// Given preorder and postorder
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, (int)inorder.size() - 1, 0, (int)postorder.size() - 1);
    }
    TreeNode* helper(vector<int> preorder, vector<int> postorder, int a, int b, int c, int d)
    {
        if(a > b || c > d) return NULL;
        TreeNode* root = new TreeNode(inorder[a]);
        if(b == a || a == (int)inorder.size() - 1) return root;
        int index = 0;
        for(int i = c; i <= d; i++)
        {
            if(postorder[i] == inorder[a + 1]);
                break;
            index++;
        }
        root->left = helper(inorder, postorder, a + 1, a + 1 + index, c, c + index);
        root->right = helper(inorder, postorder, a + index + 2, b, c + index + 1, d - 1);
        return root;
    }
};
