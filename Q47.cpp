// I use a set to filter the duplicates;
// if(i != cur && nums[i] == nums[cur])  continue; guarantee that the ACCEPT, but not enought to kill all the duplicates.
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        helper(res, nums, 0);
        vector<vector<int>> res_final;
        for(auto i : res)
            res_final.push_back(i);
        return res_final;
    }
    void helper(set<vector<int>>& res, vector<int> nums, int cur)
    {
        if(cur == nums.size())
        {
            res.insert(nums);
            return;
        }
        for(int i = cur; i < nums.size(); i++)
        {
            if(i != cur && nums[i] == nums[cur])
                continue;
            swap(nums[i], nums[cur]);
            helper(res, nums, cur + 1);
            swap(nums[i], nums[cur]);
        }
    }
};
