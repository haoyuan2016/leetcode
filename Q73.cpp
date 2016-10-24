// Solution one:
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][j] == INT_MIN / 2;
                    int a = 0;
                    int b = 0;
                    while(a < n)
                    {
                        if(matrix[i][a] != 0)
                            matrix[i][a] = INT_MIN / 2;
                        a++;
                    }
                    while(b < m)
                    {
                        if(matrix[b][j] != 0)
                            matrix[b][j] = INT_MIN / 2;
                        b++;
                    }
                }
            }
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == INT_MIN / 2)
                    matrix[i][j] = 0;
        return;
    }
};
