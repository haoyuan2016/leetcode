class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 1);
        int cur = 2;
        while(cur < n)
        {
            cur++;
            int tmpMax = 0;
            for(int i = 1; i < cur - 1; i++)
            {
                tmpMax = max(max(tmpMax, i * dp[cur - i]), i * (cur - i));
            }
            dp[cur] = tmpMax;
        }
        return dp.back();
    }
};
