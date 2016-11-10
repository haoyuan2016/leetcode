//Note that we can write a private function to write the body of BSTIterator(){};
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode* ptr = root;
        while(ptr)
        {
            s.push(ptr);
            ptr = ptr->left;
        }
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* tmp = s.top();
        s.pop();
        int res = tmp->val;
        tmp = tmp->right;
        while(tmp != NULL)
        {
            s.push(tmp);
            tmp = tmp->left;
        }
        return res;
    }
private:
    stack<TreeNode*> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
