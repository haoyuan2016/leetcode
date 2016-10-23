class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        int cur = m - 1;
        while(cur >= 1)
        {
            for(int i = 1; i <= n - 1; i++)
                dp[i] = dp[i] + dp[i - 1];
            cur--;
        }
        return dp[n - 1];
    }
};
