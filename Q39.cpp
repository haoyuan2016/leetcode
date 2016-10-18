// Note that we need to sourt candidates first, and then we can use the "target >= candidates[i]" condition in helper function.
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> container;
        sort(candidates.begin(), candidates.end());
        helper(res, container, candidates, target, 0);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& container, vector<int> candidates, int target, int cur)
    {
        if(target == 0)
        {
            res.push_back(container);
            return;
        }
        for(int i = cur; i < candidates.size() && target >= candidates[i]; i++)
        {
            container.push_back(candidates[i]);
            helper(res, container, candidates, target - candidates[i], i);
            container.pop_back();
        }
    }
};
