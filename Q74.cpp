class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int rows = matrix.size(), cols = matrix[0].size();
        int a = rows - 1, b = 0;
        while(a >= 0 && b < cols)
        {
            if(matrix[a][b] < target)
                b++;
            else if(matrix[a][b] > target)
                a--;
            else
                return true;
        }
        return false;
    }
};
