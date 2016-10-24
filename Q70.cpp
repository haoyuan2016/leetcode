class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = 2;
        int cur = 2;
        while(cur <= n - 1)
        {
            dp[cur] = dp[cur - 1] + dp[cur - 2];
            cur++;
        }
        return dp[cur - 1];
    }
};
