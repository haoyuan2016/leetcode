class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty())
            return res;
        int m = matrix.size();
        int n = matrix[0].size();
        int cur = 0;
        while(2 * cur < m && 2 * cur < n)
        {
            for(int j = cur; j < n - cur; j++)
                res.push_back(matrix[cur][j]);
            for(int i = cur + 1; i < m - cur; i++)
                res.push_back(matrix[i][n - cur - 1]);
            for(int j = n - cur - 2; m - cur - 1 != cur && j >= cur; j--)
                res.push_back(matrix[m - cur - 1][j]);
            for(int i = m - cur - 2; cur != n - cur - 1 && i >= cur + 1; i--)
                res.push_back(matrix[i][cur]);
            cur++;
        }
        return res;
    }
};
