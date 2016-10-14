class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MAX/2;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(i != 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1; int k = nums.size() - 1;
            while(j < k)
            {
                if(j != i + 1 && nums[j] == nums[j - 1])
                {
                    j++;
                    continue;
                }
                else if(k != nums.size() - 1 && nums[k] == nums[k + 1])
                {
                    k--;
                    continue;
                }
                else if(abs(nums[j] + nums[k] + nums[i] - target) < abs(res - target))
                    res = nums[j] + nums[k] + nums[i];
                else
                ;
                if(res - target == 0)
                    return res;
                else if(nums[j] + nums[k] + nums[i] - target < 0)
                    j++;
                else
                    k--;
            }
        }
        return res;
    }
};
// similar as Q.15, note that we cannot move both iterators at the same time, we need to move only one iterator at one time.
