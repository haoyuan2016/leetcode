class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(); 
        int n = grid[0].size();
        int res = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1')
                {
                    res++;
                    findIsland(grid, i, j, m, n);
                }
                    
            }
        return res;
    }
    void findIsland(vector<vector<char>>& grid, int i, int j, int m, int n)
    {
        grid[i][j] = 'X';
        if(i > 0 && grid[i - 1][j] == '1')
            findIsland(grid, i - 1, j, m, n);
        if(i < m - 1 && grid[i + 1][j] == '1')
            findIsland(grid, i + 1, j, m, n);
        if(j > 0 && grid[i][j - 1] == '1')
            findIsland(grid, i, j - 1, m, n);
        if(j < n - 1 && grid[i][j + 1] == '1')
            findIsland(grid, i, j + 1, m, n);
    }
};
