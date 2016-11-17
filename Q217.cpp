// Sort and compare
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty()) return false;
        if(nums.size() == 1) return false;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++)
            if(nums[i] == nums[i + 1])
                return true;
        return false;
    }
};
// We can also use a set<int> with extra space.
