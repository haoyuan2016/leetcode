class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty()) return -1;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(k == 1) return nums[n - 1];
        int cur = 1;
        int cur_max = nums[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            if(nums[i] <= cur_max)
            {
                cur_max = nums[i];
                cur++;
                if(cur == k) return cur_max;
            }
        }
        return -1;
    }
};

// Also see solution on  https://discuss.leetcode.com/topic/15256/4-c-solutions-using-partition-max-heap-priority_queue-and-multiset-respectively
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        while(true)
        {
            int pos = getPos(nums, left, right);
            if(k == pos + 1) return nums[pos];
            else if(k > pos + 1)
                left = pos + 1;
            else
                right = pos - 1;
        }
        return -1;
    }
    int getPos(vector<int>& nums, int left, int right)
    {
        int l = left + 1; 
        int r = right;
        while(l <= r)
        {
            if(nums[l] < nums[left] && nums[r] > nums[left])
                swap(nums[l], nums[r]);
            if(nums[l] >= nums[left]) l++;
            if(nums[r] <= nums[left]) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};
