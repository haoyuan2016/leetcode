class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            if(m.find(nums[i]) == m.end())
                m.insert({nums[i], i});
            else
            {
                if(i - m[nums[i]] <= k)
                    return true;
                else
                    m[nums[i]] = i;
            }
        }
        return false;
    }
};
// Another solution is to set set<int>, which maintains all the elements with in a interval [i,j], j - i <= k. 
// If the input data set is too large, use set may be a better idea, otherwise our map<int, int> becomes huge.
