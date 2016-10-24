// My first solution, not fast enough
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        int nn = n;
        while(nn > 0)
        {
            tmp.push_back(nn);
            nn--;
        }
        vector<vector<int>> res;
        vector<int> tmpHolder;
        helper(res, tmpHolder, tmp, k, 0);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& tmpHolder, vector<int> tmp, int k, int cur)
    {
        if(tmpHolder.size() == k)
        {
            res.push_back(tmpHolder);
            return;
        }
        for(int i = cur; i < tmp.size(); i++)
        {
            tmpHolder.push_back(tmp[i]);
            helper(res, tmpHolder, tmp, k, i + 1);
            tmpHolder.pop_back();
        }
    }
};
// Solution two, much faster
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmpHolder;
        helper(res, tmpHolder, n, k);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& tmpHolder, int n, int k)
    {
        if(tmpHolder.size() == k)
        {
            res.push_back(tmpHolder);
            return;
        }
        while(n > 0)
        {
            tmpHolder.push_back(n);
            helper(res, tmpHolder, n - 1, k);
            tmpHolder.pop_back();
            n--;
        }
    }
};
