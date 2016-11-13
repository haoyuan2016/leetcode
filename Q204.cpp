class Solution {
public:
    int countPrimes(int n) {
        if(n <= 0) return 0;
        if(n == 1) return 0;
        vector<bool> dp(n, true);
        dp[0] = false; // n = 0;
        dp[1] = false; // n = 1;
        int cur = 2;
        while(cur <= sqrt(n))
        {
            if(dp[cur] == false)
            {
                cur++;
                continue;
            }
            int tmp = cur;
            while(cur * tmp < n)
            {
                dp[cur * tmp] = false;
                tmp++;
            }
            cur++;
        }
        return count(dp.begin(), dp.end(), true);
    }
};
