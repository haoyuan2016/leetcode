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
