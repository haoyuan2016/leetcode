class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.empty()) return true; 
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = 1; j <= i + 1; j++)
            {
                string tmp = s.substr(i - j + 1, j);
                if(dp[i - j + 1] && wordDict.find(tmp) != wordDict.end())
                {
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[n];
        
    }
};
