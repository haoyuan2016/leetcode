 class Solution {
public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int n = nums.size();
            int start = -1; 
            int end = -1;
            helper(nums, 0, n - 1, target, start, end);
            vector<int> res;
            res.push_back(start);
            res.push_back(end);
            return res;
        }
        void helper(vector<int>& nums, int left, int right, int target, int& start, int& end)
        {
            if(left > right || (start != -1 && end != -1))
                return;
            int mid = left + (right - left) / 2;
            if(nums[mid] < target)
                helper(nums, mid + 1, right, target, start, end);
            else if(nums[mid] > target)
                helper(nums, left, mid - 1, target, start, end);
            else // (nums[mid] == target)
            {
                if(mid == 0 || mid - 1 >= 0 && nums[mid - 1] != target)
                    start = mid;
                if(mid + 1 == (int)nums.size() && nums[mid] == target || mid + 1 < (int)nums.size() && nums[mid + 1] != target)
                    end = mid;
                helper(nums, mid + 1, right, target, start, end);
                helper(nums, left, mid - 1, target, start, end);
            }
        }
};
