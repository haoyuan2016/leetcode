class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        int m = triangle.size();
        vector<int> dp(m, 0);
        int cur = 0;
        while(cur < m)
        {
            vector<int> tmp = dp;
            dp[0] = dp[0] + triangle[cur][0];
            if(cur > 0) dp[cur] = tmp[cur - 1] + triangle[cur][cur];
            for(int i = 1; i <= cur - 1; i++)
                dp[i] = min(tmp[i - 1] + triangle[cur][i], tmp[i] + triangle[cur][i]);
            cur++;
        }
        int res = INT_MAX;
        for(int a : dp)
            res = min(res, a);
        return res;
    }
};
