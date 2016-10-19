class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res, nums, 0);
        set<vector<int>> set;
        return res;
        
    }
    void helper(vector<vector<int>>& res, vector<int> nums, int cur)
    {
        if(cur == nums.size())
        {
            res.push_back(nums);
            return;
        }
        for(int i = cur; i < nums.size(); i++)
        {
            swap(nums[i], nums[cur]);
            helper(res, nums, cur + 1);
            swap(nums[i], nums[cur]);
        }
    }
};
