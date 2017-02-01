class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.empty()) return false;
        int n = nums.size();
        if(n < 3) return false;
        int large = INT_MAX;
        int small = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > large) return true;
            else if(nums[i] > small && nums[i] < large)
            {
                large = nums[i];
            }
            else if(nums[i] < small)
            {
                small = nums[i];
            }
        }
        return false;
    }
};
