class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty() || nums.size() == 1) return true;
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {   
            if(dp[i - 1] - 1 < 0) 
                return false;
            dp[i] = max(dp[i - 1] - 1, nums[i]);
            if(i + dp[i] >= nums.size() - 1)
                return true;
        }
        return false;
    }
};
