class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty())
            return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(obstacleGrid[m - 1][n - i - 1] == 0)
                dp[i] = 1;
            else break;
        }
        int cur = m - 1;
        while(cur >= 1)
        {
            for(int i = 0; i <= n - 1; i++)
            {
                if(obstacleGrid[cur - 1][n - i - 1] == 1)
                    dp[i] = 0;
                else
                    dp[i] = dp[i] + dp[i - 1];
            }   
                
            cur--;
        }
        return dp[n - 1];
    }
};
