class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maxPositive = nums[0];
        int maxNegative = nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < 0)
                swap(maxPositive, maxNegative);
            maxPositive = max(maxPositive * nums[i], nums[i]);
            maxNegative = min(maxNegative * nums[i], nums[i]);
            res = max(res, maxPositive);
        }
        return res;
    }
};
