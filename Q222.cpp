// BFS, time out
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int lens = q.size();
            while(lens > 0)
            {
                lens--;
                TreeNode* tmp = q.front();
                q.pop();
                res++;
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
        }
        return res;
    }
};
// Solution two, still time out
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
// Solution three
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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int l = 1;
        int r = 1;
        TreeNode* ln = root->left;
        TreeNode* rn = root->right;
        while(ln)
        {
            ln = ln->left;
            l++;
        }
        while(rn)
        {
            rn = rn->right;
            r++;
        }
        if(l == r) return pow(2, l) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
        
    }
};
