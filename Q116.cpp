/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            TreeLinkNode* tFirst = q.front();
            q.pop();
            if(tFirst->left) q.push(tFirst->left);
            if(tFirst->right) q.push(tFirst->right);
            while(n > 1)
            {
                n--;
                TreeLinkNode* tmp = q.front();
                q.pop();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
                tFirst->next = tmp;
                tFirst = tmp;
            }
            tFirst->next = NULL;
        }
    }
};
