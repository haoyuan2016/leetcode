class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
            {
                if(mid + 1 == n || mid + 1 < n && nums[mid + 1] > target)
                    return mid + 1;
                else
                    left = mid + 1;
            }
            else // nums[mid] > target
            {
                if(mid == 0)
                    return 0;
                else if(nums[mid - 1] < target)
                    return mid;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
