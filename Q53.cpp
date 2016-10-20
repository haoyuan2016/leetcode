// Solution one, not fast enough. We need to handle the case that the final answer is smaller than 0;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int negative_max = nums[0];
        int res = INT_MIN;
        int cur_max = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            negative_max = max(negative_max, nums[i]);
            if(nums[i] <= 0)
            {
                res = max(res, cur_max);
                cur_max += nums[i];
                if(cur_max < 0)
                    cur_max = 0;
            }
            else
                cur_max += nums[i];
        }
        return max(res, cur_max) == 0? negative_max: max(res, cur_max);
    }
};

// Solution two: find a good way to handle the negative case.
// In each iteration, we calculate cur_max = cur_max + nums[i]; and res = max(res, cur_max);
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int cur_max = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            cur_max = cur_max + nums[i];
            res = max(res, cur_max);
            if(cur_max < 0)
                cur_max = 0;
        }
        return res;
    }
};
