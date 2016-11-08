class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] >= nums[l])
            {
                if(nums[mid] > nums[r])
                    l = mid + 1;
                else 
                    r = mid - 1;
            }
            else // nums[mid] <= nums[l]
            {
                r = mid;
            }
        }
        return nums[l];
    }
};
