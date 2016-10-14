// I write a code that cannot slove the unique issue.
// If I use a set to filter the result, then it cause time out. The attached is my code without "unique" property
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> container;
        helper(res, container, nums, 0);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& container, vector<int> nums, int cur)
    {
        if(container.size() == 3)
        {
            if(container[0] + container[1] + container[2] == 0)
                res.push_back(container);
            return;
        }
        for(int i = cur; i < nums.size(); i++)
        {
            container.push_back(nums[i]);
            helper(res, container, nums, i + 1);
            container.pop_back();
        }
    }
};
