//Solution one: it has some problem, fails to calculate the permutation.
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> holder;
        vector<vector<int>> con;
        int start = 0;
        helper(nums, target, holder, con, start);
        return con.size();
    }
    void helper(vector<int> &nums, int target, vector<int> &holder, vector<vector<int>> & con, int start)
    {
        if(target == 0)
        {
            con.push_back(holder);
            return;
        }
        for(int i = start; target >= 0 && i < nums.size(); i++)
        {
            holder.push_back(nums[i]);
            helper(nums, target - nums[i], holder, con, i);
            holder.pop_back();
        }
    }
};
// solution two: it can get the correct result, but time out.
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0)
            return 1;
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(target >= nums[i])
                res += combinationSum4(nums, target- nums[i]);
        }
        return res;
    }
};
// solution three, use dp method, finally accepted.
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        sort (nums.begin(), nums.end());
        for (int i = 1; i <= target; i++) {
            for (auto num : nums) {
                if (i < num) break;
                dp[i] += dp[i - num];
            }
        }
        return dp.back();
    }
};
