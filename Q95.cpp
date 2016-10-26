// Code one: This code is almost right, except that there may be duplicates in the result. We need a set to filter it.
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n == 0)
            return res;
        int tmp = 1;
        vector<int> nums;
        while(tmp <= n)
        {
            nums.push_back(tmp);
            tmp++;
        }
        vector<vector<int>> holder;
        helper(holder, nums, 0);
        for(vector<int> a : holder)
        {
            TreeNode* root = new TreeNode(a[0]);
            for(int i = 1; i < a.size(); i++)
                insert(root, a[i]);
            res.push_back(root);
        }
        return res;
    }
    void helper(vector<vector<int>>& holder, vector<int>& nums, int cur)
    {
        if(cur == nums.size())
        {
            holder.push_back(nums);
            return;
        }
        for(int i = cur; i < nums.size(); i++)
        {
            swap(nums[i], nums[cur]);
            helper(holder, nums, cur + 1);
            swap(nums[cur], nums[i]);
        }
    }
    void insert(TreeNode*& root, int tar)
    {
        if(root == NULL)
        {
            root = new TreeNode(tar);
            return;
        }
        if(root->val > tar)
            insert(root->left, tar);
        else
            insert(root->right, tar);
    }
};


// This question takes me so much time, the main problem is that when we use the DP method, the values on the right child should be 
// upadted, but it also updated the original DP value. So we use a copyNode function to redesign the right child.
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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return vector<TreeNode*>{};
        vector<TreeNode*> res;
        TreeNode* root = new TreeNode(1);
        unordered_map<int, vector<TreeNode*>> dp;
        dp[0].push_back(NULL);
        dp[1].push_back(root);
        int cur = 2;
        while(cur <= n)
        {
            for(int i = 1; i <= cur; i++)
            {
                TreeNode* ptr = new TreeNode(i);
                int l = i - 1;
                int r = cur - i;
                addNodes(l, r, ptr, dp, cur);
            }
            cur++;
        }
        return dp[n];
    }
    
    void addNodes(int l, int r, TreeNode* ptr,  unordered_map<int, vector<TreeNode*>>& dp, int cur){
        for(auto a : dp[l])
            for(auto b : dp[r])
            {
                TreeNode* tmp = new TreeNode(ptr->val);
                tmp->left = a;
                if(b != NULL)
                {
                    TreeNode* bb = new TreeNode(b->val);
                    copyNode(bb, b);
                    plusR(bb, ptr->val);
                    tmp->right = bb;
                }
                dp[cur].push_back(tmp);
            }
    }
    void copyNode(TreeNode* ptr1, TreeNode* ptr2)
    {
        if(ptr2 == NULL)
            return;
        if(ptr2->left)
        {
            ptr1->left = new TreeNode(ptr2->left->val);
            copyNode(ptr1->left,ptr2->left);
        }
        if(ptr2->right)
        {
            ptr1->right = new TreeNode(ptr2->right->val);
            copyNode(ptr1->right, ptr2->right);
        }
    }
	void plusR(TreeNode*& root, int n)
	{
		if (root == NULL)
			return;
		root->val += n;
		plusR(root->left, n);
		plusR(root->right, n);
	}
};

