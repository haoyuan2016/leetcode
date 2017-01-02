// O(N^2) solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n, 1);
        int res = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
// for O(NlogN) slotion, see the attached links.
// see https://segmentfault.com/a/1190000003819886
// also http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
