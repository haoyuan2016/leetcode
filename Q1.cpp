class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            m[nums[i]] = i;
        }
        for(int i = 0; i < m.size(); i++)
        {
            if(m.find(target - nums[i]) != m.end() && m.find(target - nums[i])->second != i)
            {
                res.push_back(i);
                res.push_back(m.find(target - nums[i])->second);
                return res;
            }
        }
        return res;
    }
};

// Note: The complexity of find() in unorder_map is constant.
