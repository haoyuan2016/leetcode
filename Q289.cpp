class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int tmp = 0;
                if(i > 0 && j > 0)
                    if(board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == 2) tmp++;
                if(i > 0)
                    if(board[i - 1][j] == 1 || board[i - 1][j] == 2) tmp++;
                if(i > 0 && j < n - 1)
                    if(board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == 2) tmp++;
                if(j > 0)
                    if(board[i][j - 1] == 1 || board[i][j - 1] == 2) tmp++;
                if(j < n - 1)
                    if(board[i][j + 1] == 1 || board[i][j + 1] == 2) tmp++;
                if(i < m - 1 && j > 0)
                    if(board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == 2) tmp++;
                if(i < m - 1)
                    if(board[i + 1][j] == 1 || board[i + 1][j] == 2) tmp++;
                if(i < m - 1 && j < n - 1)
                    if(board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == 2) tmp++;
                if(board[i][j] == 0)
                {
                    if(tmp == 3)
                        board[i][j] = 3;
                }
                else
                {
                     if(tmp < 2 || tmp > 3)
                        board[i][j] = 2;  
                }
            }
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                board[i][j] = board[i][j] % 2;
        return;
    }
};
