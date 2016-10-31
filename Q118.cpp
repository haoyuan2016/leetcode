class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return vector<vector<int>>{};
        if(numRows == 1) return vector<vector<int>>{vector<int>{1}};
        vector<vector<int>> res;
        res.push_back(vector<int>{1});
        int cur = 2;
        while(cur <= numRows)
        {
            vector<int> tmp(cur, 1);
            for(int i = 1; i < cur - 1; i++)
                tmp[i] = res[cur - 2][i - 1] + res[cur - 2][i];
            res.push_back(tmp);
            cur++;
        }
        return res;
    }
};
