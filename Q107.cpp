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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        res.push_back(vector<int>{root->val});
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            int cur =0;
            vector<int> tmp;
            while(cur < n)
            {
                cur++;
                TreeNode* ptr = q.front();
                q.pop();
                if(ptr->left)
                {
                    q.push(ptr->left);
                    tmp.push_back(ptr->left->val);
                }
                if(ptr->right)
                {
                    q.push(ptr->right);
                    tmp.push_back(ptr->right->val);
                }
            }
            if(!tmp.empty()) res.push_back(tmp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
