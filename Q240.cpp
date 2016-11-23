class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int m = matrix.size(); 
        int n = matrix[0].size();
        int i = m - 1; 
        int j = 0;
        while(i >= 0 && j < n)
        {
            if(target == matrix[i][j])
                return true;
            else if(target > matrix[i][j])
                j++;
            else
                i--;
        }
        return false;
    }
};
// Space O(1), time O(m * n) for worst case.
