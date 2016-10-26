class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        if(s[0] == '0') return 0;
        int n = s.length();
        if(n == 1)
            return 1;
        vector<int> dp(n, 0);
        dp[0] = 1;
        if(s[1] == '0')
        {
            if(s[0] >= '3') return 0;
            else dp[1] = 1;
        }
        else
        {
            if(s[0] == '2' && s[1] <= '6' || s[0] < '2')
                dp[1] = 2;
            else
                dp[1] = 1;
        }
            
        for(int i = 2; i < n; i++)
        {
            // if s[i] cannot use s[i - 1]
            if(s[i] == '0')
            {
                if(s[i - 1] == '0' || s[i - 1] >= '3')
                    return 0;
                else
                    dp[i] = dp[i - 2];
            }
            else if(s[i - 1] < '2' && s[i - 1] > '0' || s[i - 1] == '2' && s[i] <= '6')  // can use s[i - 1];
            {
                    dp[i] = dp[i - 2] + dp[i - 1];
            }
            else // cannot use s[i - 1]
                dp[i] = dp[i - 1];
        }
        return dp[n - 1];
    }
};
