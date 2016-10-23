class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,0));
        int cur = 1;
        int loop = (n + 1) / 2;
        int cur_loop = 0;
        while(cur_loop <= loop - 1)
        {
            for(int i = cur_loop; i < n - cur_loop; i++)
                res[cur_loop][i] = cur++;
            for(int i = cur_loop + 1; i < n - cur_loop; i++)
                res[i][n - cur_loop - 1] = cur++;
            for(int i = n - 2 - cur_loop; i >= cur_loop; i--)
                res[n - cur_loop - 1][i] = cur++;
            for(int i = n - 2 - cur_loop; i >= 1 + cur_loop; i--)
                res[i][cur_loop] = cur++;
            cur_loop++;
        }
        return res;
    }
};
