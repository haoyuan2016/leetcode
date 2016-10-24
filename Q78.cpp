class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> holder;
        int n = nums.size();
        int pick = 0;
        while(pick <= n)
        {
            helper(res, holder, nums, pick ,0);
            pick++;
        }
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& holder, vector<int> nums, int pick, int cur)
    {
        if(holder.size() == pick)
        {
            res.push_back(holder);
            return;
        }
        for(int i = cur ; i < nums.size(); i++)
        {
            holder.push_back(nums[i]);
            helper(res, holder, nums, pick, i + 1);
            holder.pop_back();
        }
    }
};
