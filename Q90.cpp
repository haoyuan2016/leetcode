class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> holder;
        helper(res, holder, nums, 0);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& holder, vector<int> nums, int cur)
    {
        res.push_back(holder);
        for(int i = cur; i < nums.size(); i++)
        {
            if(i > cur && nums[i] == nums[i - 1]) continue;
            holder.push_back(nums[i]);
            helper(res, holder, nums, i + 1);
            holder.pop_back();
        }
    }
};
