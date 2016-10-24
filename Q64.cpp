class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);
        dp[0] = grid[0][0];
        for(int i = 1; i < n; i++)
            dp[i] = dp[i - 1] + grid[0][i];
        int row = 1;
        while(row <= m - 1)
        {
            dp[0] = dp[0] + grid[row][0];
            for(int j = 1; j < n; j++)
                dp[j] = min(dp[j], dp[j - 1]) + grid[row][j];
            row++;
        }
        return dp[n - 1];
    }
};
