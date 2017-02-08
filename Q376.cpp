class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        if(n == 1) return 1;
        vector<int> sign(n, 0); // 0 eight +,-, -1 -, 1 +;
        vector<int> dp(n, 1);   // the Max length at element i;
        dp[0] = 1;
        sign[0] = 0;
        for(int i = 1; i <= n - 1; i++)
        {
            int localSign = -2;
            int localMax = INT_MIN;
            for(int j = 0; j <= i - 1; j++)
            {
                if(nums[i] - nums[j] == 0)
                    continue;
                else if(nums[i] - nums[j] > 0 && (sign[j] == -1 || sign[j] == 0))
                {
                    localMax = max(localMax, dp[j] + 1);
                    localSign = 1;
                }
                else if(nums[i] - nums[j] < 0 && (sign[j] == 1 || sign[j] == 0))
                {
                    localMax = max(localMax, dp[j] + 1);
                    localSign = -1;
                }
                dp[i] = localMax;
                sign[i] = localSign;
            }
        }
        return dp[n - 1];
    }
};
