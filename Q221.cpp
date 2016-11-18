class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        if(matrix.empty()) return 0;
        int m = matrix.size(); 
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        if(matrix[0][0] == '1') dp[0][0] = 1;
            res = max(dp[0][0], res);
        for(int i = 1; i < n; i++)
        {
            if(matrix[0][i] == '1')
            {
                dp[0][i] = 1;
                res = max(dp[0][i], res);
            }
            else
                dp[0][i] = 0;
        }
        for(int j = 1; j < m; j++)
        {
            if(matrix[j][0] == '1')
            {
                dp[j][0] = 1;
                res = max(dp[j][0], res);
            }
            else
                dp[j][0] = 0;
        }
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(matrix[i][j] == '1')
                {
                    int tmp = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                    dp[i][j] = (sqrt(tmp) + 1) * (sqrt(tmp) + 1);
                    res = max(dp[i][j], res);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return res;
    }
};
