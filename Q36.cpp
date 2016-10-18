// The interesting part is how to use paramenter k, which denotes the k-th sub 3*3 square, to iterator.
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int column = board[0].size();
        if(row != 9 || column != 9) return false;
        for(int i = 0; i < row; i++)
        {
            vector<bool> v(9,false);
            for(int j = 0; j < column; j++)
            {
                if(board[i][j] == '.')
                    continue;
                else
                {   
                    if(v[board[i][j]] == true)
                        return false;
                    v[board[i][j]] = true;
                }
            }
        }
        for(int i = 0; i < column; i++)
        {
            vector<bool> v(false);
            for(int j = 0; j < row; j++)
            {
                if(board[j][i] == '.')
                    continue;
                else
                {
                    if(v[board[j][i]] == true)
                        return false;
                    v[board[j][i]] = true;
                }
            }
        }
        int k = 0;
        while(k < 9)
        {
            vector<bool> v(9,false);
            for(int i = 3 * (k / 3); i < 3 * (k / 3) + 3; i++)
                for(int j = 3 * (k % 3); j < 3 * (k % 3) + 3; j++)
                {
                    if(board[i][j] == '.')
                        continue;
                    else
                    {
                        if(v[board[i][j]] == true)
                            return false;
                        v[board[i][j]] = true;
                    }
                }
            k++;
        }
        return true;
    }
};
