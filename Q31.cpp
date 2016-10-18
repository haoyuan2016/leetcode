//Great job! If we do not use the swap(nums[i - 1], nums[index]), we cannot obtain the fastest solution

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i = n - 1; i > 0; i--)
        {
            int small = INT_MAX;
            int index;
            if(nums[i] <= nums[i - 1])
            {
                if(i - 1 == 0)
                    return sort(nums.begin(), nums.end());
                continue;
            }
            for(int j = n - 1; j >= i; j--)
            {
                if(nums[j] > nums[i - 1] && nums[j] < small)
                {
                    small = nums[j];
                    index = j;
                }
            }
            swap(nums[i - 1], nums[index]);
            sort(nums.begin() + i, nums.end());
            return;
        }
    }
};
