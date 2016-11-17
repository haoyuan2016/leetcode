// Solution one
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> vec;
        int tmp = 1;
        while(tmp < 10)
        {
            vec.push_back(tmp);
            tmp++;
        }
        vector<vector<int>> res;
        vector<int> holder;
        helper(res, k, n, holder, vec, 0);
        return res;
    }
    void helper(vector<vector<int>>& res, int k, int target, vector<int>& holder, vector<int>& vec, int cur)
    {
        if(holder.size() == k)
        {
            if(target == 0)
            {
                res.push_back(holder);
                return;
            }
            else
                return;
        }
        for(int i = cur; i < vec.size(); i++)
        {
            holder.push_back(vec[i]);
            helper(res, k, target - vec[i], holder, vec, i + 1);
            holder.pop_back();
        }
    }
};
// Modified
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> holder;
        helper(res, k, n, holder, 1);
        return res;
    }
    void helper(vector<vector<int>>& res, int k, int target, vector<int>& holder, int cur)
    {
        if(holder.size() == k)
        {
            if(target == 0)
            {
                res.push_back(holder);
                return;
            }
            else
                return;
        }
        for(int i = cur; i < 10; i++)
        {
            holder.push_back(i);
            helper(res, k, target - i, holder, i + 1);
            holder.pop_back();
        }
    }
};
