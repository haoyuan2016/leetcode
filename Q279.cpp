class Solution {
public:
    int numSquares(int n) {
        vector<int> perfectSquares(n + 1, INT_MAX);
        perfectSquares[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j * j <= i; j++)
            {
                perfectSquares[i] = min(perfectSquares[i], perfectSquares[i - j * j] + 1);
            }
        }
        return perfectSquares.back();
    }
};
// double check https://discuss.leetcode.com/topic/24255/summary-of-4-different-solutions-bfs-dp-static-dp-and-mathematics/42
// the static vector is faster than this solution.
