class Solution {
public:
    int numTrees(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        int tmp = 1;
        while(tmp <= n)
        {
            int l;
            int r;
            for(int i = 1; i <= tmp; i++)
            {
                l = i - 1;
                r = tmp - i;
                dp[tmp] += dp[l] * dp[r];
            }
            tmp++;
        }
        return dp[n];
    }
};
