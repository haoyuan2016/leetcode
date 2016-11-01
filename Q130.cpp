class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int m = board.size(); 
        int n = board[0].size();
        for(int i = 0; i < n; i++)
        {
            if(board[0][i] == 'O')
                isO(board, 0, i, m, n);
            if(m > 1 && board[m - 1][i] == 'O')
                isO(board, m - 1, i, m, n);
        }
        for(int j = 0; j < m; j++)
        {
            if(board[j][0] == 'O')
                isO(board, j, 0, m, n);
            if(n > 1 && board[j][n - 1] == 'O')
                isO(board, j, n - 1, m, n);
        }
        for(int i = 1; i < m - 1; i++)
            for(int j = 1; j < n - 1; j++)
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(board[i][j] == 'S')
                    board[i][j] = 'O';
    }
    void isO(vector<vector<char>>& board, int i, int j, int m, int n)
    {
        board[i][j] = 'S';
        if(i > 1 && board[i - 1][j] == 'O')
            isO(board, i - 1, j, m, n);
        if(i < m - 2 && board[i + 1][j] == 'O')
            isO(board, i + 1, j, m, n);
        if(j > 1 && board[i][j - 1] == 'O')
            isO(board, i, j - 1, m, n);
        if(j < n - 2 && board[i][j + 1] == 'O')
            isO(board, i, j + 1, m, n);
    }
};
