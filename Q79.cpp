// I first use a vector<vector<bool>> to state whether a point is visited, but time out.
// We do not need another bool vector, we can simply change the value of board[i][j]
// Pay attention that the backtracking method needs to restore the state of board[i][j] after we changed it!!!!! Used a lot of time here.
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()) return true;
        if(board.empty()) return false;
        int m = board.size(), n = board[0].size();
        if(word.length() > m * n)
            return false;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(board[i][j] == word[0])
                    if (check(board, word, i, j, 0))
                        return true; 
        return false;
    }
    bool check(vector<vector<char>>& board, string word, int i, int j, int cur)
    {
        int m = board.size(), n = board[0].size();
        if(i < m && i >=0 && j >=0 && j < n && cur < word.length() && board[i][j] == word[cur])
        {
            if(cur == word.length() - 1)
                return true;
            else
            {
                char tmp = board[i][j];
                board[i][j] = 'a' - 1;
                if(check(board, word, i - 1, j, cur + 1)) 
                    return true;
                if(check(board, word, i + 1, j, cur + 1))
                    return true;
                if(check(board, word, i, j - 1, cur + 1))
                    return true;
                if(check(board, word, i, j + 1, cur + 1))
                    return true;
                board[i][j] = tmp;
            }
        }
        return false;
    }
};
