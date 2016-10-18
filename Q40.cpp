class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            if(i != cur && candidates[i] == candidates[i - 1])
                continue;
            container.push_back(candidates[i]);
            helper(res, container, candidates, target - candidates[i], i + 1);
            container.pop_back();
        }
    }
};
